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
    int n, m; cin >> n >> m;
    vvi a(n, vi(m));
    rep(i, n) rep(j, m) cin >> a[i][j];
    vvi mn(n, vi(m, INFi));
    vvi mx(n, vi(m, -INFi));
    mn[0][0] = mx[0][0] = a[0][0];
    rep(i, n) {
        rep(j, m) {
            if (i) {
                mn[i][j] = min(mn[i][j], a[i][j] + mn[i - 1][j]);
                mx[i][j] = max(mx[i][j], a[i][j] + mx[i - 1][j]);
            }
            if (j) {
                mn[i][j] = min(mn[i][j], a[i][j] + mn[i][j - 1]);
                mx[i][j] = max(mx[i][j], a[i][j] + mx[i][j - 1]);
            }
        }
    }
    if (mn[n - 1][m - 1] % 2 == 0 && mn[n - 1][m - 1] <= 0 && mx[n - 1][m - 1] >= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}