#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int N = 1e6 + 10, INF = 1e9;
vector<int> g[N], mx[N], mn(N, INF);
int x, ans = 0, d[N], n;

void zhfs(int v, int p) {
    for (auto to : g[v]) {
        if (to != p) {
            d[to] = d[v] + 1;
            zhfs(to, v);
        }
    }
}

void dfs(int v, int p) {
    int u = -1;
    for (auto to : g[v]) {
        if (to != p) {
            dfs(to, v);
            if (u == -1 || mx[to].size() > mx[u].size()) {
                u = to;
            }
        }
    }
    if (u != -1) {
        swap(mx[v], mx[u]);
        for (auto to : g[v]) {
            if (to != p && to != u) {
                for (int i = 0; i < mx[to].size(); i++) {
                    while (1) {
                        int j = max(0, ans + 1 - i - x);
                        if (j < mx[v].size()) {
                            if (mx[to][i] + mx[v][j] - 2 * d[v] > ans) {
                                ans++;
                                continue;
                            }
                        }
                        break;
                    }
                }
                for (int i = 0; i < mx[to].size(); i++) {
                    mx[v][i] = max(mx[v][i], mx[to][i]);
                }
            }
        }
    }
    while (1) {
        int j = max(0, ans + 1 - mn[v] - x);
        if (j < mx[v].size()) {
            if (mx[v][j] - d[v] > ans) {
                ans++;
                continue;
            }
        }
        break;
    }
    if (mn[v] < mx[v].size()) {
        mx[v][mn[v]] = max(mx[v][mn[v]], d[v]);
    } else {
        assert(mn[v] == mx[v].size());
        mx[v].pb(d[v]);
    }
}

void bfs() {
    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            mn[i] = 0;
            q.pb(i);
        }
    }
    while (q.size() > 0) {
        int v = q.front();
        q.pop_front();
        for (auto to : g[v]) {
            if (mn[to] == INF) {
                mn[to] = mn[v] + 1;
                q.pb(to);
            }
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].pb(i);
        g[i].pb(p);
    }
    bfs();
    int r = -1;
    for (int i = 0; i < n; i++) {
        if (g[i].size() >= 2) {
            r = i;
        }
    }
    zhfs(r, -1);
    int q;
    cin >> q;
    while (q--) {
        cin >> x;
        ans = 0;
        for (int i = 0; i < n; i++) {
            mx[i].clear();
        }
        dfs(r, -1);
        cout << ans << ' ';
    }
    return 0;
}