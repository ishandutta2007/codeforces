#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
//#define string basic_string<unsigned char>
#define char unsigned char

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<vector<int> > q(n - 2, vector<int>(3, 0));
    vector<int> cnt(n, 0);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 2; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        z--;
        q[i] = {x, y, z};
        cnt[x]++;
        cnt[y]++;
        cnt[z]++;
        g[x].push_back(i);
        g[y].push_back(i);
        g[z].push_back(i);
    }
    int t = 0;
    while (cnt[t] != 1)
        t++;
    vector<int> p;
    p.push_back(t);
    int x = 0;
    for (int i : g[t])
        for (int j : q[i])
            if (cnt[j] == 2)
                x = j;
    p.push_back(x);
    while (sz(p) < n)
    {
        int r = p.back();
        int e = p[sz(p) - 2];
        for (int i : g[r])
        {
            bool ok = 0;
            for (int j : q[i])
                if (j == e)
                    ok = 1;
            if (ok)
            {
                int xx = 0;
                while (q[i][xx] == r || q[i][xx] == e)
                    xx++;
                if (sz(p) < 3 || q[i][xx] != p[sz(p) - 3])
                {
                    p.push_back(q[i][xx]);
                    break;
                }
            }
        }
    }
    for (int i : p)
        cout << i + 1 << '\n';
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    // cin >> TET;
    for (int i = 1; i <= TET; i++)
    {
        if (solve())
            break;
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}