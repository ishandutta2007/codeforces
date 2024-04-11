#include <iostream>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int level = 0;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == '(')
        {
            if (level % 2 == 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
            level++;
        }
        else
        {
            level--;
            if (level % 2 == 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
    }
    return 0;
}