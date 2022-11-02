#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> g[N], val(N), par(N);
bool bad = 0;

void dfs(int v, int p) {
    vector<int> cnt(2);
    for (auto to : g[v]) {
        if (to != p) {
            par[to] = v;
            dfs(to, v);
            cnt[val[to]]++;
        }
    }
    if (p != -1) {
        if (cnt[0] >= cnt[1]) {
            val[v] = 1;
        } else {
            val[v] = 0;
        }
        cnt[val[v]]++;
    }
    if (cnt[1] < cnt[0] || cnt[1] > cnt[0] + 1) {
        bad = 1;
    }
}

void zhfs(int v, int p) {
    vector<vector<int>> all(2);
    for (auto to : g[v]) {
        if (to == p) to = v;
        all[val[to]].pb(to);
    }
    for (int i = 0; i < g[v].size(); i++) {
        int j = ((int)(g[v].size()) - i) & 1;
        int u = all[j].back();
        if (u == v) {
            cout << u + 1 << ' ' << par[u] + 1 << endl;
        } else {
            zhfs(u, v);
        }
        all[j].pop_back();
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) g[i].clear();
        bad = 0;
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(0, -1);
        if (bad) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        zhfs(0, -1);
    }
    return 0;
}