#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
//#include<unordered_set>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double

mt19937 rnd(51);

const int N = 1010;
vector<int> g[N];
vector<bool> used(N);
vector<int> d(N);

void ask(vector<int> v)
{
    cout << "?" << " " << v.size() << " ";
    for (auto to : v)
    {
        cout << to << " ";
    }
    cout << endl;
}

void dfs(int v)
{
    used[v] = 1;
    for (auto to : g[v])
    {
        if (!used[to])
        {
            d[to] = d[v] + 1;
            dfs(to);
        }
    }
}

void solve()
{
    vector<int> kek;
    int n, need = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        kek.pb(i);
    }
    for (int i = 0; i < N; i++)
    {
        g[i].clear();
        used[i] = 0;
        d[i] = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    ask(kek);
    cin >> need >> need;
    dfs(1);
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, d[i]);
    }
    int l = -1, r = mx + 1, j = 0;
    while(r - l > 1)
    {
        int mid = (r + l) / 2;
        vector<int> lol;
        for (int i = 1; i <= n; i++)
        {
            if (d[i] >= mid)
            {
                lol.pb(i);
            }
        }
        ask(lol);
        int i, mn;
        cin >> i >> mn;
        if (mn == need)
        {
            l = mid;
            j = i;
        }
        else
        {
            r = mid;
        }
    }
    kek.clear();
    kek.pb(1);
    ask(kek);
    int d1;
    cin >> d1 >> d1;
    d1 = (d1 - need) / 2;
    int d2 = d1 + (need - (d[j] - d1));
    kek.clear();
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == d2)
        {
            kek.pb(i);
        }
    }
    ask(kek);
    int v, lol;
    cin >> v >> lol;
    bool x = 0;
    deque<int> q;
    q.push_back(v);
    while(q.size() > 0)
    {
        int u = q.front();
        q.pop_front();
        if (u == j) x = 1;
        for (auto to : g[u])
        {
            if (d[to] > d[u])
            {
                q.push_back(to);
            }
        }
    }
    if (x)
    {
        int last = v;
        vector<int> kek1;
        for (auto to : kek)
        {
            if (to != v)
            {
                kek1.pb(to);
            }
        }
        if (kek1.size() != 0) {
        ask(kek1);
        cin >> v >> lol;
        if (lol != need){
            v = last;
        }
        }
    }
    cout << '!' << " " << v << " " << j << endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
        string s;
        cin >> s;
        if (s == "Correct") continue;
        else
        {
            exit(0);
        }
    }
    return 0;
}