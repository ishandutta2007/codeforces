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
const int maxN = 5e6 + 30;
const int LG = 100;
const int md = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vi have(m + 1);
    vi cnt(m + 1, 0);
    vi dp(m + 1, 0);
    dp[1] = 1;
    rep(i, n) {
        int x;
        cin >> x;
        have[x]++;
        cnt[dp[x]]++;
    }
    while (have[m] == 0) m--;
    int l = 0;
    int ans = (m == 1 ? 0 : INFi);
    for (int r = 2; r <= m; ++r) {
        cnt[dp[r]] -= have[r];
        dp[r] = r;
        cnt[dp[r]] += have[r];
        for (int x = r * 2, d = 2; x <= m; x += r, d += 1) {
            if (dp[x] < dp[d]) {
                cnt[dp[x]] -= have[x];
                dp[x] = dp[d];
                cnt[dp[x]] += have[x];
            }
        }
        while (cnt[l] == 0) l++;
        if (l != 0) ans = min(ans, r - l);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}