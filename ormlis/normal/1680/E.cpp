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
const int maxN = (1 << 20) + 1;
const int LG = 30;

void solve() {
    int n;
    cin >> n;
    vector<string> a(2);
    rep(i, 2) cin >> a[i];
    vector<int> dp(4, INFi);
    dp[0] = -1;
    int R = n - 1;
    while (a[1][R] == '.' && a[0][R] == '.') R--;
    rep(i, R + 1) {
        vi dp2(4, INFi);
        int mask = 0;
        if (a[0][i] == '*') mask |= 1;
        if (a[1][i] == '*') mask |= 2;
        if (dp[0] == -1) {
            if (mask == 0) continue;
            dp2[mask] = 0;
        } else {
            rep(was, 4) {
                if (dp[was] == INFi) continue;
                dp2[was | mask] = min(dp2[was | mask], dp[was] + 1 + was / 3);
            }
        }
        dp2[1] = min(dp2[1], dp2[3] + 1);
        dp2[2] = min(dp2[2], dp2[3] + 1);
        swap(dp, dp2);
    }
    cout << min(dp[1], dp[2]) << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}