#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<pair<int,int>> g[N];
vector<int> gr[N], res;
vector<bool> was(N);

void dfs(int v) {
    was[v] = 1;
    for (auto to : gr[v]) {
        if (!was[to]) {
            dfs(to);
        }
    }
    res.pb(v);
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n), ind(n);
    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            int j = i, cnt = 0;
            while (!used[j]) {
                used[j] = 1;
                ind[j] = cnt++;
                j = p[j];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb({y, i});
        g[y].pb({x, i});
    }
    for (int i = 0; i < n; i++) {
        int sz = g[i].size();
        sort(g[i].begin(), g[i].end(), [&](pair<int,int> a, pair<int,int> b){return ind[a.first] < ind[b.first];});
        int j = 0;
        while (j < g[i].size()) {
            if (ind[g[i][j].first] < ind[i]) {
                j++;
            } else {
                break;
            }
        }
        for (int k = 0; k + 1 < sz; k++) {
            int a = (k + j) % sz, b = (k + j + 1) % sz;
            gr[g[i][a].second].pb(g[i][b].second);
        }
    }
    for (int i = 0; i < m; i++) {
        if (!was[i]) {
            dfs(i);
        }
    }
    reverse(res.begin(), res.end());
    for (auto to : res) {
        cout << to + 1 << ' ';
    }
    cout << endl;
    return 0;
}