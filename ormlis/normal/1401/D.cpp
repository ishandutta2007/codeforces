#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];
vector<ll> kek;
int n;

int dfs(int v, int p) {
    int res = 1;
    for(auto &u: g[v]) {
        if (u == p) continue;
        res += dfs(u, v);
    }
    if (p != 0) kek.push_back(1ll * res * (n - res));
    return res;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) g[i].clear();
    kek.clear();
    range(i, n - 1) {
        int u, v; cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int m; cin >> m;
    vector<int> pr(m);
    range(i, m) cin >> pr[i];
    dfs(1, 0);
    sort(all(pr));
    sort(rall(kek));
    while(pr.size() > kek.size()) {
        int c = pr.back();
        pr.pop_back();
        pr.back() = mul(pr.back(), c);
    }
    int ans = 0;
    reverse(all(pr));
    while(pr.size() < kek.size()) pr.push_back(1);
    range(i, n - 1) ans = add(ans, mul(pr[i], kek[i] % md));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}