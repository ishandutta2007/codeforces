#pragma comment(linker,"/STACK:200000000")

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <random>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>

using namespace std;

const string filename = "tree40";
bool interactive = true;

int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    int y, x;

    cin >> y >> x;

    vector<string> table (y);

    for (auto &it : table)
        cin >> it;

    int posx = 0, posy = -1;

    for (int i = 0; posy == -1; i++)
        for (int j = 0; j < x; j++)
            if (table[i][j] == 'X')
            {
                posx = j;
                posy = i;

                break;
            }

    int lx = 0, ly = -1;

    for (int i = y - 1; ly == -1; i--)
        for (int j = x - 1; j >= 0; j--)
            if (table[i][j] == 'X')
            {
                lx = j;
                ly = i;

                break;
            }

    bool ans = true;

    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            if ((table[i][j] == 'X') ^ (lx >= j && posx <= j && ly >= i && posy <= i))
                ans = false;

    cout << (ans ? "YES" : "NO") << endl;


    return 0;
}