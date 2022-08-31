#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e3 + 5;
const int LG = 20;

const int K = 500;

void solve() {
    int n, l, k; cin >> n >> l >> k;
    vi d(n);
    rep(i, n) cin >> d[i];
    vi a(n);
    rep(i, n) cin >> a[i];
    d.push_back(l);
    a.push_back(0);
    vec<vl> dp(n + 1, vl(k + 1));
    for(int i = 1; i <= n; ++i) {
        rep(j, k + 1) dp[i][j] = INF;
        for(int j = i - 1; j >= 0; --j) {
            for(int t = 0; t + (i - j - 1) <= k; ++t) {
                dp[i][t + (i - j - 1)] = min(dp[i][t + (i - j - 1)], dp[j][t] + 1ll * (d[i] - d[j]) * a[j]);
            }
        }
    }
    cout << dp[n][k] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}