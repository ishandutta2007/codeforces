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

struct aho
{
    const int AL = 26;
    int n;
    vector<vector<int> > g;
    vector<int> link;
    vector<ll> cost;

    aho(vector<string> s, vector<int> a)
    {
        n = 1;
        g.assign(1, vector<int>(AL, -1));
        link.assign(1, 0);
        cost.assign(1, 0);
        for (int i = 0; i < sz(s); i++)
        {
            string t = s[i];
            int v = 0;
            for (char c : t)
            {
                c -= 'a';
                if (g[v][c] == -1)
                {
                    g.push_back(vector<int>(AL, -1));
                    link.push_back(-1);
                    cost.push_back(0);
                    g[v][c] = n++;
                }
                v = g[v][c];
            }
            cost[v] += a[i];
        }
        queue<int> q;
        q.push(0);
        vector<int> used(n, 0);
        while (q.size())
        {
            int v = q.front();
            used[v] = 1;
            q.pop();
            for (int i = 0; i < sz(g[v]); i++)
            {
                int &u = g[v][i];
                if (u == -1)
                {
                    if (v == 0)
                    {
                        u = 0;
                    }
                    else
                    {
                        u = g[link[v]][i];
                    }
                }
                else if (!used[u])
                {
                    if (v == 0)
                    {
                        link[u] = 0;
                    }
                    else
                    {
                        link[u] = g[link[v]][i];
                    }
                    q.push(u);
                }
                used[u] = 1;
            }
        }
        vector<ll> cost1 = cost;
        for (int i = 0; i < n; i++)
        {
            int v = i;
            while (v)
            {
                v = link[v];
                cost1[i] += cost[v];
            }
        }
        cost = cost1;
    }
};

const ll INF = -1e18;

vector<vector<ll> > prod(vector<vector<ll> > a, vector<vector<ll> > b)
{
    int n = sz(a);
    vector<vector<ll> > c(n, vector<ll>(n, -1));
    for (int i = 0; i < n; i++)
    {

    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (a[i][k] >= 0 && b[k][j] >= 0)
                {
                    c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
                }
            }
        }
    }
    return c;
}

vector<vector<ll> > binpow(vector<vector<ll> > mtr, ll y)
{
    if (y == 1)
    {
        return mtr;
    }
    if (y % 2)
    {
        return prod(binpow(mtr, y - 1), mtr);
    }
    return binpow(prod(mtr, mtr), y / 2);
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    ll l;
    cin >> l;
    vector<int> a(n);
    for (int &i : a)
    {
        cin >> i;
    }
    vector<string> s(n);
    for (string &t : s)
    {
        cin >> t;
    }
    aho corasic(s, a);
    vector<vector<ll> > mtr(corasic.n, vector<ll>(corasic.n, -1));
    for (int i : corasic.cost)
    {
//        cout << i << endl;
    }
    for (int i = 0; i < corasic.n; i++)
    {
        for (int u : corasic.g[i])
        {
            mtr[i][u] = max(corasic.cost[u], mtr[i][u]);
        }
    }
    mtr = binpow(mtr, l);
    ll ans = 0;
    for (ll i : mtr[0])
    {
        ans = max(ans, i);
    }
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    int T = 1;
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    for (int i = 1;; i++)
    //cin >> T; for (int i = 1; i <= T; i++)
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