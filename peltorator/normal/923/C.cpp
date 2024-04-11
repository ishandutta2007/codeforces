#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>

#define sz(a) (int)((a).size())

using namespace std;

typedef long long ll;
typedef long double ld;

struct bor
{
    vector<vector<int> > g;
    vector<int> cnt;
    int n;
    bor()
    {
        n = 1;
        g.assign(1, vector<int>(2, -1));
        cnt.assign(1, 0);
    }
    void inc(int x, int d)
    {
        int v = 0;
        for (int i = 29; i >= 0; i--)
        {
            cnt[v] += d;
            if ((x & (1 << i)))
            {
                if (g[v][1] == -1)
                {
                    g[v][1] = n++;
                    g.push_back(vector<int>(2, -1));
                    cnt.push_back(0);
                }
                v = g[v][1];
            }
            else
            {
                if (g[v][0] == -1)
                {
                    g[v][0] = n++;
                    g.push_back(vector<int>(2, -1));
                    cnt.push_back(0);
                }
                v = g[v][0];
            }
        }
        cnt[v] += d;
    }
};

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    bor b;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        b.inc(p[i], 1);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        int v = 0;
        for (int bit = 29; bit >= 0; bit--)
        {
            int curbit = ((a[i] >> bit) & 1);
            if (b.g[v][curbit] != -1 && b.cnt[b.g[v][curbit]] > 0)
            {
                if (curbit)
                {
                    cur |= (1 << bit);
                }
                v = b.g[v][curbit];
            }
            else
            {
                if (!curbit)
                {
                    cur |= (1 << bit);
                }
                v = b.g[v][!curbit];
            }
        }
      //  cout << cur << endl;
        ans[i] = (cur ^ a[i]);
        b.inc(cur, -1);
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

int32_t main()
{
    int T = 1;
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    for (int i = 1;; i++)
    //cin >> T; for (int i = 0; i < T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}