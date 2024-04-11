#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10;
int par[N], tin[N], bal[N], cnt[N], kol = 0;
vector<bool> used(N);
vector<int> g[N];

void dfs(int v, int p) {
    par[v] = p;
    tin[v] = kol++;
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to, v);
        }
    }
}

void zhfs(int v, int p) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            zhfs(to, v);
            bal[v] += bal[to];
        }
    }
    cnt[v] = (bal[v] != 1);
}

void gfs(int v, int p) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            cnt[to] += cnt[v];
            gfs(to, v);
        }
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> q(m);
    map<pair<int,int>, int> mp;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        q[i] = {u, v};
        mp[{u, v}] = mp[{v, u}] = i;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            arr.pb(i);
            dfs(i, -1);
        }
    }
    for (auto [u, v] : q) {
        if (par[u] == v || par[v] == u) continue;
        if (tin[u] < tin[v]) swap(u, v);
        bal[u]++, bal[v]--;
    }
    fill(used.begin(), used.end(), 0);
    for (auto v : arr) {
        zhfs(v, -1);
    }
    fill(used.begin(), used.end(), 0);
    for (auto v : arr) {
        gfs(v, -1);
    }
    vector<int> ans;
    for (auto [u, v] : q) {
        if (par[u] == v || par[v] == u) continue;
        if (tin[u] < tin[v]) swap(u, v);
        if (cnt[u] == cnt[v]) {
            ans.pb(mp[{u, v}]);
            while (u != v) {
                ans.pb(mp[{par[u], u}]);
                u = par[u];
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto to : ans) {
        cout << to + 1 << ' ';
    }
    cout << endl;
    return 0;
}