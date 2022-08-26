#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5+1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];
int need_del[maxN];
int p[maxN];
int rev[maxN];
int tin[maxN];
int t = 0;

void dfs(int v) {
    tin[v] = t++;
    for (auto u: g[v]) {
        if (u == p[v]) continue;
        if (p[u]) {
            if (tin[u] < tin[v]) rev[v] = u;
            continue;
        }
        p[u] = v;
        dfs(u);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    range(i, m) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!p[i]) {
            p[i] = -1;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (rev[i]) {
            int v = rev[i];
            int u = i;
            vector<int> cycle = {v};
            while (u != v) {
                cycle.push_back(u);
                u = p[u];
            }
            int mn = *min_element(all(cycle));
            int mx = *max_element(all(cycle));
            need_del[mx] = mn;
        }
    }

    vector<ll> ps(n + 5, 0);
    vector<int> time_del(n + 5, n + 5);
    time_del[0] = 1;
    for(int i = 1, j = 0; i <= n; ++i) {
        while (j < need_del[i]) {
            j++;
            time_del[j] = i;
        }
        ps[i] = ps[i-1] + i - j;
    }

    int q; cin >> q;
    range(_, q) {
        int l, r; cin >> l >> r;
        int l2 = min(time_del[l-1] - 1, r);
        cout << ps[r] - ps[l2] + 1ll * (l2 - l + 1) * (l2 - l + 2) / 2 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}