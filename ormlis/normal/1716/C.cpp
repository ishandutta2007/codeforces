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
using i128 = __int128;
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
const int LG = 20;
const int maxN = 2e5 + 10;

void solve() {
    int n; cin >> n;
    vvi a(2, vi(n));
    rep(i, 2) rep(j, n) cin >> a[i][j];
    a[0][0] = -1;
    vvi mxp(2, vi(n)), mxs(2, vi(n));
    rep(i, 2) rep(j, n) {
        mxp[i][j] = a[i][j] + j;
        mxs[i][j] = a[i][j] - j;
    }
    rep(i, 2) for(int j = n - 2; j >= 0; --j) {
        ckmax(mxp[i][j], mxp[i][j + 1]);
        ckmax(mxs[i][j], mxs[i][j + 1]);
    }
    int ans = INFi;
    int cur = 0;
    rep(i, n) {
        int val_up = mxs[0][i] + n + (n - i);
        int val_down = mxp[1][i] - i + 1;
        ans = min(ans, max({cur, val_up, val_down}));
        cur = max(cur, a[0][i] + (n - i) * 2);
        cur = max(cur, a[1][i] + (n - i) * 2 - 1);
        swap(mxp[0], mxp[1]);
        swap(mxs[0], mxs[1]);
        swap(a[0], a[1]);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}