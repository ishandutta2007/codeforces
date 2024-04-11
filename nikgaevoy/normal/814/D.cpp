#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <cstdio>
#include <ctime>
#include <cassert>

using namespace std;

const double pi = 3.14159265358979323846;

template<class T>
T sqr (T x)
{
    return x * x;
}

double foo (const vector<vector<int>> &tree, const vector<double> &w, int n, bool am = 0, bool pm = 0)
{
    static vector<double> dp (1 << 16);
    static vector<bool> q (1 << 16);

    int state = n | (am << 14) | (pm << 15);

    if (!q[state])
    {
        q[state] = true;

        double a = am ? -w[n] : w[n];
        double b = pm ? -w[n] : w[n];

        for (auto it : tree[n])
        {
            a += foo (tree, w, it, !am, pm);
            b += foo (tree, w, it, am, !pm);
        }

        dp[state] = max (a, b);
    }

    return dp[state];
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<pair<int, pair<int, int>>> danc (n);

    for (auto &it : danc)
        cin >> it.second.first >> it.second.second >> it.first;

    sort (danc.rbegin (), danc.rend ());

    vector<vector<int>> tree (n);
    vector<double> w (n);
    vector<bool> root (n, true);

    for (int i = 0; i < n; i++)
    {
        w[i] = pi * sqr ((long long)danc[i].first);

        for (int j = i - 1; j >= 0; j--)
            if (sqr (danc[i].second.first - (long long)danc[j].second.first) +
                sqr (danc[i].second.second - (long long)danc[j].second.second) <=
                sqr ((long long)danc[j].first))
            {
                tree[j].push_back (i);
                root[i] = false;

                break;
            }
    }

    double ans = 0;

    for (int i = 0; i < n; i++)
        if (root[i])
            ans += foo (tree, w, i);

    cout.precision (20);
    cout << fixed << ans << endl;

    return 0;
}