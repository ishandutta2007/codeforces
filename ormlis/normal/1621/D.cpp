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
const int maxN = 6e6 + 100;
const int LG = 20;

void solve() {
    int n;
    cin >> n;
    vvi a(2 * n, vi(2 * n, 0));
    rep(i, n * 2) {
        rep(j, n * 2) {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    ll add = 0;
    for (int i = n; i < 2 * n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            add += a[i][j];
        }
    }
    ans = min({a[n - 1][n], a[n][n - 1], a[0][2 * n - 1], a[2 * n - 1][0], a[0][n],
               a[n - 1][2 * n - 1], a[n][0], a[2 * n - 1][n - 1]});
    cout << ans + add << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}