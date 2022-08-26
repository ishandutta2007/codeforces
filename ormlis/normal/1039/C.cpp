#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 5e5 + 1;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int add(int a, int b) {
    return (a + b < md ? a + b : a + b - md);
}

int sub(int a, int b) {
    return (a - b >= 0 ? a - b : a - b + md);
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b == 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int mid = binpow(a, b / 2);
    return mul(mid, mid);
}

ll c[maxN];
vector<int> g[maxN];
map<ll, vector<pair<int, int>>> mp;

map<int, vector<int>> g2;
map<int, int> used;

int dfs(int v) {
    used[v] = 1;
    int res = 1;
    for (auto &u: g2[v]) {
        if (used[u]) {
            continue;
        }
        res += dfs(u);
    }
    return res;
}

int n, m, k;

int solve2(ll x) {
    g2.clear();
    used.clear();
    for (auto &p: mp[x]) {
        g2[p.first].push_back(p.second);
        g2[p.second].push_back(p.first);
    }
    int cnt1 = n;
    int ans = 1;
    for (auto &v: g2) {
        if (!used[v.first]) {
            cnt1 -= dfs(v.first);
            ans = mul(ans, 2);
        }
    }
    ans = mul(ans, binpow(2, cnt1));
    return ans;
}

void solve() {
    cin >> n >> m >> k;
    range(i, n) cin >> c[i];
    range(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[(c[u] ^ c[v])].emplace_back(u, v);
    }
    int ans = 0;
    for (auto &x: mp) ans = add(ans, solve2(x.first));
    int others = sub(binpow(2, k), mp.size());
    others = mul(others, binpow(2, n));
    ans = add(ans, others);
    cout << ans;
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