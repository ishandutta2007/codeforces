#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
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
const int maxN = 2e5 + 30;
const int LG = 20;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    {
        int j = 0;
        rep(i, n) if (j != m && s[i] == t[j]) j++;
        if (j != m) {
            cout << "-1\n";
            return;
        }
    }
    int ans = INFi;
    rep(i, n + 1) {
        if (i == m || s[i] != t[i]) {
            ans = min(ans, n - i);
            break;
        }
    }
    rep(i, n + 1) {
        if (i == m || s[n - 1 - i] != t[m - 1 - i]) {
            ans = min(ans, 1 + (n - i) + (n - m));
            break;
        }
    }
    vvi dp(m + 1, vi(3, INFi));
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;
    rep(i, n) {
        vvi dp2(m + 1, vi(3, INFi));
        rep(e, 3) {
            rep(j, m + 1) {
                if (dp[j][e] == INFi) continue;
                if (e + 1 < 3) dp[j][e + 1] = min(dp[j][e + 1], dp[j][e]);
                // skip
                if (e != 1) {
                    dp2[j][e] = min(dp2[j][e], dp[j][e] + 1 + int(e == 0));
                }
                if (j != m && t[j] == s[i]) {
                    dp2[j + 1][e] = min(dp2[j + 1][e], dp[j][e] + int(e != 1));
                }
            }
        }
        swap(dp, dp2);
    }
    cout << min(ans, *min_element(all(dp[m]))) << '\n';
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