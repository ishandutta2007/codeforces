#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <complex>
#include <cstdio>
#include <ctime>

using namespace std;
const int inf = int (1e9 + 7);

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    string str;

    str.reserve (n + 1);

    cin >> str;

    int pos = 0, R = 0, D = 0;

    while (true)
    {
        if (str[pos % n] == 'R')
        {
            if (D < pos)
                D = pos + 1;

            while (D < pos + n && str[D % n] != 'D')
                D++;

            if (str[D % n] == 'D')
                str[D % n] = ' ';
            else
            {
                cout << 'R' << endl;

                return 0;
            }
        }
        else if (str[pos % n] == 'D')
        {
            if (R <= pos)
                R = pos + 1;

            while (R < pos + n && str[R % n] != 'R')
                R++;

            if (str[R % n] == 'R')
                str[R % n] = ' ';
            else
            {
                cout << 'D' << endl;

                return 0;
            }
        }

        pos++;
    }

    return 0;
}