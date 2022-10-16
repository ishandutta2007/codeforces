#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <algorithm>
#include <functional>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>

#pragma comment(linker,"/STACK:200000000")

using namespace std;

const int inf = int (1e9) + 7;
const double pi = 3.1415926535897932384626433;
const double eps = 1e-4;

const string filename = "test";
const bool interactive = true;

int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, c;

    cin >> n >> c;

    vector<int> cost (n), time (n);

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    for (int i = 0; i < n; i++)
        cin >> time[i];

    int fs = 0, ss = 0;

    for (int i = 0, t = 0; i < n; i++)
    {
        t += time[i];
        fs += max (0, cost[i] - c * t);
    }

    for (int i = n - 1, t = 0; i >= 0; i--)
    {
        t += time[i];
        ss += max (0, cost[i] - c * t);
    }

    cout << (fs > ss ? "Limak" : fs == ss ? "Tie" : "Radewoosh") << endl;

    return 0;
}