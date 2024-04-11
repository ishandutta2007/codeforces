#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>

#define REL 0

#if REL
    #include <conio.h>
#endif

using namespace std;
const int inf = int (1e9);

int main ()
{
    ios_base::sync_with_stdio (false);

    int n;
    cin >> n;
    vector<bool> lvl (n);

    for (int i = 0; i < n; i++)
    {
        char tmp;

        cin >> tmp;

        if (tmp != '.' && tmp != '*')
            i--;
        else
            lvl[i] = (tmp == '*');
    }

    for (int i = 0; i < n; i++)
    {
        if (lvl[i])
        {
            for (int j = 1; (j << 2) + i < n; j++)
            {
                bool flag = true;

                for (int num = 0; num < 5; num++)
                {
                    if (!lvl[i + j * num])
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    cout << "yes";
#if REL
                    _getch ();
#endif
                    return 0;
                }
            }
        }
    }

    cout << "no";

#if REL
    _getch ();
#endif
    return 0;
}