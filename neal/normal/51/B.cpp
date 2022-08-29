#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int TABLE = 1, CELL = 2;

string S = "";
vector <int> V, sizes;

int main ()
{
    string next;

    while (getline (cin, next))
        S += next;

    for (int i = 0; i < (int) S.length (); i++)
        if (S [i] == '<')
        {
            int j = i + 1, mult = 1;

            if (S [j] == '/')
            {
                j++;
                mult = -1;
            }

            if (S [j + 1] == 'a')
                V.push_back (mult * TABLE);
            else if (S [j + 1] == 'd')
                V.push_back (mult * CELL);
        }

    for (int i = 0; i < (int) V.size (); i++)
        if (V [i] == TABLE)
        {
            int tables = 1, cells = 0;

            for (int j = i + 1; j < (int) V.size (); j++)
                if (V [j] == TABLE)
                    tables++;
                else if (V [j] == -TABLE)
                {
                    tables--;

                    if (tables == 0)
                        break;
                }
                else if (V [j] == CELL && tables == 1)
                    cells++;

            sizes.push_back (cells);
        }

    sort (sizes.begin (), sizes.end ());

    for (int i = 0; i < (int) sizes.size (); i++)
        cout << sizes [i] << (i + 1 < (int) sizes.size () ? ' ' : '\n');

    return 0;
}