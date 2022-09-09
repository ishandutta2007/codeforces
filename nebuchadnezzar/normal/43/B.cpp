#include <iostream>

using namespace std;
string a, b;
int main()
{
    getline(cin, a);
    getline (cin, b);
    int i, j;
    bool ex;
    for(i = 0; i < b.size(); ++i)
    {
        ex = true;
        if(b[i] != ' ')
        {
            for(j = 0; j < a.size(); ++j)
            {
                if(b[i] == a[j])
                {
                    ex = false;
                    a[j] = ' ';
                    break;
                }
            }
        }
        else
        {
            ex = false;
        }
        if(ex == true)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}