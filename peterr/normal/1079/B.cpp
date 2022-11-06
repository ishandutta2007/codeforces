#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   string s;
   cin >> s;

   if (s.length() <= 20)
   {
      cout << 1 << " " << s.length() << endl;
      cout << s;
   }
   else
   {
      int rows = ceil(s.length() / 20.0);
      int cols = ceil(s.length() / static_cast<double>(rows));
      int ast = rows * cols - s.length();
      int index = 0;

      cout << rows << " " << cols << endl;

      for (int r = 0; r < rows; r++)
      {
         if (ast-- > 0)
         {
            cout << "*";
            cout << s.substr(index, cols - 1);
            index += cols - 1;
         }
         else
         {
            cout << s.substr(index, cols);
            index += cols;
         }
         cout << endl;
      }
   }
}