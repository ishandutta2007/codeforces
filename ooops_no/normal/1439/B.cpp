#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5 + 10;
vector<int> g[N];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[ {a, b}] = 1;
        mp[ {b, a}] = 1;
        g[a].pb(b);
        g[b].pb(a);
    }
    if (k > 500)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> col(n + 1);
    set<pair<int,int>> st;
    for (int i = 1; i <= n; i++)
    {
        col[i] = g[i].size();
        st.insert({col[i], i});
    }
    while(st.size() > 0)
    {
        pair<int,int> p = *st.begin();
        if (p.first >= k)
        {
            break;
        }
        st.erase(p);
        for (auto to : g[p.second])
        {
            if (col[to] >= k)
            {
                st.erase({col[to], to});
                col[to]--;
                st.insert({col[to], to});
            }
        }
    }
    if (st.size() != 0)
    {
        cout << 1 << " " << st.size() << endl;
        for (auto to : st)
        {
            cout << to.second << " ";
        }
        cout << endl;
        return;
    }
    k--;
    vector<int> used(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        col[i] = g[i].size();
        st.insert({col[i], i});
    }
    vector<int> good(n + 1);
    vector<vector<int>> check;
    vector<vector<int>> need(n + 1);
    while(st.size() > 0)
    {
        pair<int,int> p = *st.begin();
        used[p.second] = 0;
        if (p.first > k)
        {
            break;
        }
        int i = p.second;
        if (p.first == k)
        {
            vector<int> u;
            u.pb(i);
            for (auto to : g[i])
            {
                if (used[to])
                {
                    u.pb(to);
                }
            }
            if (u.size() == k + 1)
            {
                good[check.size()] = 1;
                check.pb(u);
                for (auto to : u){
                    need[to].pb(check.size() - 1);
                }
            }
        }
        st.erase(p);
        for (auto to : g[p.second])
        {
            if (used[to])
            {
                st.erase({col[to], to});
                col[to]--;
                st.insert({col[to], to});
            }
        }
    }
    vector<int> now(n + 1);
    for (int i = 1; i <= n; i++){
        vector<int> have;
        have.pb(i);
        now[i] = 1;
        for (auto to : g[i]){
                now[to] = 1;
                have.pb(to);
        }
        for (auto to : need[i]){
            for (auto t : check[to]){
                good[to] &= now[t];
            }
        }
        for (auto to : have){
            now[to] = 0;
        }
    }
    for (int i = 0; i <= n; i++){
        if (good[i]){
            cout << 2 << endl;
            for (auto to : check[i]){
                cout << to << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}