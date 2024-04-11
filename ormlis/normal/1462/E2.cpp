#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
using namespace std;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int fact[maxN];

int rev(int a) {
    return binpow(a, md - 2);
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fact[n], rev(mul(fact[k], fact[n - k])));
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> positions(n);
    range(i, n) {
        int a; cin >> a;
        positions[a - 1].push_back(i);
    }
    int ans = 0;
    int cnt = 0;
    range(mx, n) {
        ans = sub(ans, C(cnt, m));
        cnt += positions[mx].size();
        ans = add(ans, C(cnt, m));
        if (mx - k >= 0) {
            cnt -= positions[mx - k].size();
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}