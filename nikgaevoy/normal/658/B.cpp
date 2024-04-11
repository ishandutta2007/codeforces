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

    unsigned n, q, k;

    cin >> n >> k >> q;

    unsigned m = 0;

    vector<unsigned> friends (n), online;
    vector<bool> ans (n);

    online.reserve (k + 1);

    for (unsigned i = 0; i < n; i++)
        scanf ("%ld", &friends[i]);

    for (unsigned i = 0; i < q; i++)
    {
        unsigned type, id;

        scanf ("%ld%ld", &type, &id);
        id--;

        if (type == 1)
        {
            online.push_back (friends[id]);
            ans[id] = true;
            sort (online.begin (), online.end (), greater<int> ());
            if (online.size () > k)
            {
                online.pop_back ();
                m = online.back ();
            }
        }
        else if (type == 2)
            printf ((ans[id] && friends[id] >= m) ? "YES\n" : "NO\n");
    }

    return 0;
}