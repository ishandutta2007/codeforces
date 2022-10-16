#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <complex>
#include <functional>
#include <queue>
#include <set>
#include <random>

#include <ctime>
#include <cmath>
#include <cstdlib>

#pragma warning (disable : 4018)
#pragma comment (linker, "/STACK:200000000")

using namespace std;

const int inf = 1e9 + 7;

int dfs (const vector<vector<int>> &gr, vector<int> &siz, int v = 0, int par = -1)
{
    for (auto it : gr[v])
        if (it != par)
            siz[v] += dfs (gr, siz, it, v);

    return siz[v];
}

vector<vector<int>> ans;

bool add_command (int x, int y, int ysh)
{
    if (y != ysh)
        ans.push_back ({x + 1, y + 1, ysh + 1});

    return y != ysh;
}

void ezh_dfs (vector<vector<int>> &gr, int ezh, int v, int par, int &y, int cent)
{
    if (v != ezh)
    {
        add_command (cent, y, v);
        add_command (v, par, ezh);
        y = v;
    }

    for (auto it : gr[v])
        if (it != par && it != cent && it != cent)
            ezh_dfs (gr, ezh, it, v, y, cent);
}

void one_cent (vector<vector<int>> &gr, int cent)
{
    for (auto ezh : gr[cent])
    {
        int y = ezh;

        ezh_dfs (gr, ezh, ezh, cent, y, cent);

        add_command (cent, y, ezh);
    }
}

void two_cent (vector<vector<int>> &gr, int cent1, int cent2)
{
    for (auto ezh : gr[cent1])
        if (ezh != cent2)
        {
            int y = ezh;

            ezh_dfs (gr, ezh, ezh, cent1, y, cent1);

            add_command (cent1, y, ezh);
        }

    for (auto ezh : gr[cent2])
        if (ezh != cent1)
        {
            int y = ezh;

            ezh_dfs (gr, ezh, ezh, cent2, y, cent2);

            add_command (cent2, y, ezh);
        }
}

void foo (vector<vector<int>> &gr)
{
    vector<int> siz (gr.size (), 1);

    dfs (gr, siz);

    int cent = 0;
    bool good = false;

    while (!good)
    {
        good = true;

        for (auto it : gr[cent])
            if (siz[it] > siz[cent] / 2)
            {
                siz[cent] -= siz[it];
                siz[it] += siz[cent];

                cent = it;
                good = false;

                break;
            }
    }
    for (auto it : gr[cent])
        if (2 * siz[it] == siz[cent])
        {
            two_cent (gr, cent, it);

            return;
        }

    one_cent (gr, cent);
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, m;

    cin >> n;
    m = n - 1;

    vector<vector<int>> gr (n);

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;
        a--;
        b--;

        gr[a].push_back (b);
        gr[b].push_back (a);
    }

    foo (gr);

    cout << ans.size () << endl;

    for (auto it : ans)
        cout << it[0] << ' ' << it[1] << ' ' << it[2] << endl;

    return 0;
}