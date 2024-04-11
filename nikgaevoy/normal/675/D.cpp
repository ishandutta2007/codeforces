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
#include <cassert>
#include <random>
#include <cstdint>

#pragma comment(linker,"/STACK:200000000")

using namespace std;

const int inf = int (1e9) + 7;
const double pi = 3.1415926535897932384626433;
const double eps = 1e-9;

const string filename = "breaking-hashing";
const bool interactive = true;


int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    int n;

    cin >> n;

    vector<int> tree;

    int t;

    unordered_map<int, int> par;
    map<pair<int, int>, int> lca;

    cin >> t;
    tree.push_back (t);

    for (int i = 1; i < n; i++)
    {
        scanf ("%ld", &t);

        auto u = upper_bound (tree.begin (), tree.end (), t);

        if (u == tree.begin ())
        {
            par[t] = *u;
            lca[{t, *u}] = *u;
        }
        else
        {
            auto l = u;
            l--;

            if (u == tree.end ())
            {
                par[t] = *l;
                lca[{*l, t}] = *l;
            }
            else if (t < lca[{*l, *u}])
            {
                par[t] = *l;
                lca[{*l, t}] = *l;
                lca[{t, *u}] = lca[{*l, *u}];
            }
            else
            {
                par[t] = *u;
                lca[{*l, t}] = lca[{*l, *u}];
                lca[{t, *u}] = *u;
            }
        }

        printf (i == n - 1 ? "%ld\n" : "%ld ", par[t]);

        tree.insert (u, t);
    }

    return 0;
}