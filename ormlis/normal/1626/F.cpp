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
const int maxN = 1e7 + 5;
const int LG = 20;
const int md = 998244353; //1e9 + 7, 1e9 + 9

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

int a[maxN];
int N = 2;

int k;
int n;
int t = 0;

void solve() {
    int x, y, M;
    cin >> n >> a[0] >> x >> y >> k >> M;
    for (int i = 1; i < n; ++i) {
        a[i] = (1ll * a[i - 1] * x + y) % M;
    }
    rep(mask, 1 << k) {
        int ways = 1;
        int p = 0;
        rep(i, k) {
            if (mask & (1 << i)) {
                p = add(p, 1);
            } else {
                ways = mul(ways, n - 1);
            }
        }
        t = add(t, mul(p, ways));
    }
    int d = 1;
    for(int i = 2; i < k; ++i) {
        d *= i / __gcd(i, d);
    }
    vector<int> to(k + 1);
    to[k] = 1;
    for(int i = k - 1; i >= 1; --i) {
        to[i] = to[i + 1] * i / __gcd(i, to[i + 1]);
    }
    vector<vector<int>> dp(k + 1, vector<int> (d));
    vector<vector<int>> sb(k + 1, vector<int> (d));
    vector<vector<int>> cnt(k + 1, vector<int> (d));
    rep(i, d) {
        sb[k][i] = 1;
        cnt[k][i] = n;
    }
    for(int i = k - 1; i >= 1; --i) {
        rep(j, d) {
            int nxt = j - (j % i);
            dp[i][j] = mul(n - 1, dp[i + 1][j]);
            sb[i][j] = mul(n - 1, sb[i + 1][j]);
            cnt[i][j] = mul(n - 1, cnt[i + 1][j]);
            dp[i][j] = add(dp[i][j], sub(dp[i + 1][nxt], mul(sb[i + 1][nxt], j % i)));
            sb[i][j] = add(sb[i][j], add(sb[i + 1][nxt], cnt[i + 1][nxt]));
            cnt[i][j] = add(cnt[i][j], cnt[i + 1][nxt]);
        }
    }
    int ans = 0;
    rep(i, n) {
        ans = add(ans, mul(t, a[i]));
        ans = add(ans, dp[1][a[i]%d]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}