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
const int inf = int (1e9) + 7;

int main ()
{
    if (!interactive)
    {
        freopen ((filename + ".in").c_str (), "r", stdin);
        freopen ((filename + ".out").c_str (), "w", stdout);
    }

    unsigned n, m;

    cin >> n >> m;

    string p;

    cin >> p;

    vector<unsigned> seq (m);

    for (auto &it : seq)
    {
        cin >> it;

        it--;
    }

    sort (seq.begin (), seq.end ());

    int ans = 1;

    for (unsigned s = 0, i = 0; i < n; i++)
    {
        while (s < seq.size () && seq[s] + p.size () <= i)
            s++;

        if (s == seq.size () || i < seq[s] || seq[s] + p.size () <= i)
            ans = (26ll * ans) % inf;
    }

    vector<unsigned> z (p.size ());

    z[0] = p.size ();

    for (unsigned i = 1, l = 0, r = 0, j; i < p.size (); i++)
    {
        if (i > r)
        {
            for (j = 0; ((j + i) < p.size ()) && (p[i + j] == p[j]); j++);
            z[i] = j;
            l = i;
            r = (i + j - 1);
        }
        else
        {
            if (z[i - l] < (r - i + 1))
            {
                z[i] = z[i - l];
            }
            else
            {
                for (j = 1; ((j + r) < p.size ()) && (p[r + j] == p[r - i + j]); j++);
                z[i] = (r - i + j);
                l = i;
                r = (r + j - 1);
            }
        }
    }

    p.clear ();

    vector<bool> good (z.size ());

    for (unsigned i = 0; i < good.size (); i++)
        good[i] = i + z[i] == z.size ();

    z.clear ();

    for (unsigned i = 1; i < seq.size (); i++)
        if (seq[i] - seq[i - 1] < good.size () && !good[seq[i] - seq[i - 1]])
            ans = 0;

    cout << ans << endl;

    return 0;
}