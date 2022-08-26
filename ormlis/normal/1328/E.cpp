#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 200001;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];
vector<int> w[maxN];
bool ans[maxN];
int current[maxN];
void dfs(int v, int p) {
    for(auto &u: g[v]) {
        if (u == p) continue;
        for(auto &x: w[u]) {
            current[x]--;
            if (!current[x]) ans[x] = true;
        }
    }
    for(auto &u: g[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    for(auto &u: g[v]) {
        if (u == p) continue;
        for(auto &x: w[u]) {
            current[x]++;
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    range(i, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    range(i, m) {
        int k; cin >> k;
        current[i] = k;
        range(j, k) {
            int v; cin >> v;
            w[v].push_back(i);
        }
    }
    for(auto &x: w[1]) {
        current[x]--;
        if (!current[x]) ans[x] = true;
    }
    dfs(1, -1);
    range(i, m) {
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}