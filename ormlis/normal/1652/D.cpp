//
// Created by Ormlis (t.me/averageCFenjoyer) on 20.03.2022.
//

#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef long double ld;

using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 2e5 + 10;
const int md = 998244353;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int pw(int a, int b) {
    int r = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) r = mul(r, a);
    return r;
}

int rev(int a) {
    return pw(a, md - 2);
}

int mp[maxN];
vi primes;

void precalc() {
    for (int i = 2; i < maxN; ++i) {
        if (!mp[i]) {
            mp[i] = i;
            primes.push_back(i);
        }
        for (auto &p : primes) {
            if (p * i >= maxN || p > mp[i]) break;
            mp[p * i] = p;
        }
    }
}

vector<ar<int, 3>> g[maxN];
int cur[maxN];
int mx[maxN];

void addp(int x, int k) {
    while(x != 1) {
        int p = mp[x];
        x /= p;
        cur[p] += k;
        mx[p] = max(mx[p], cur[p]);
    }
}

int ans = 0;

void dfs(int v, int p, int val) {
    ans = add(ans, val);
    for (auto &[u, x, y] : g[v]) {
        if (u == p) continue;
        addp(y, -1);
        addp(x, 1);
        dfs(u, v, mul(mul(val, y), rev(x)));
        addp(x, -1);
        addp(y, 1);
    }
}

void solve() {
    int n;
    cin >> n;
    rep(_, n - 1) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        int w = __gcd(x, y);
        x /= w;
        y /= w;
        g[u].push_back({v, x, y});
        g[v].push_back({u, y, x});
    }
    rep(i, n + 1) cur[i] = mx[i] = 0;
    ans = 0;
    dfs(1, -1, 1);
    for(int i = 1; i <= n; ++i) g[i].clear();
    for(int i = 1; i <= n; ++i) {
        rep(_, mx[i]) ans = mul(ans, i);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    precalc();
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}