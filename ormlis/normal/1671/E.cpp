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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 4e5 + 10;
const int LG = 100;
const int md = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<char> s(1 << n);
    for (int i = 1; i < (1 << n); ++i) cin >> s[i];
    vector<string> dp(1 << n);
    for(int i = int(1 << (n - 1)); i < (1 << n); ++i) dp[i] = s[i];
    int ans = 1;
    for (int i = int(1 << (n - 1)) - 1; i >= 1; --i) {
        int L = i * 2;
        int R = i * 2 + 1;
        if (dp[L] < dp[R]) {
            dp[i] = s[i] + dp[L] + dp[R];
        } else {
            dp[i] = s[i] + dp[R] + dp[L];
        }
        if (dp[L] != dp[R]) ans = (1ll * ans * 2) % md;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}