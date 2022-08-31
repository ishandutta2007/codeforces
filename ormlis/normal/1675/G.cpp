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
const int maxN = 2e5 + 20;
const int LG = 30;

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    int M = m + 3;
    vvi dp(m + 1, vi(M * 2, INFi));
    dp[0][M] = 0;
    vi p(n + 1);
    p[0] = 0;
    rep(i, n - 1) p[i + 1] = p[i] + a[i];
    for (int i = n - 1; i >= 0; --i) {
        vvi dp2(m + 1, vi(M * 2, INFi));
        rep(last, m + 1) {
            rep(took, M * 2) {
                if (dp[last][took] == INFi) continue;
                for (int k = last; k <= m; ++k) {
                    int cur = a[i] - (took - M);
                    int took2 = k - cur;
                    if (took2 > p[i]) break;
                    took2 += M;
                    dp2[k][took2] = min(dp2[k][took2], dp[last][took] + abs(took2 - M));
                }
            }
        }
        swap(dp, dp2);
    }
    int ans = INFi;
    rep(last, m + 1) ans = min(ans, dp[last][M]);
    cout << ans << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}