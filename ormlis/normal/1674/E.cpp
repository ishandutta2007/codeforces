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
const int maxN = 1e6 + 20;
const int LG = 100;
const int md = 998244353; //1e9 + 7, 1e9 + 9

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = INFi;
    for (int i = 1; i < n; ++i) {
        int x = a[i - 1];
        int y = a[i];
        if (x > y) swap(x, y);
        if (x * 2 <= y) {
            ans = min(ans, (y + 1) / 2);
        } else {
            int t = y - x;
            x -= t;
            y -= t * 2;
            assert(x == y);
            int d = x / 3;
            int res = t + d * 2;
            res += x % 3;
            ans = min(ans, res);
        }
    }
    for (int i = 1; i + 1 < n; ++i) {
        ans = min(ans, a[i + 1] / 2 + a[i - 1] / 2 + 1);
    }
    sort(all(a));
    ans = min(ans, (a[0] + 1) / 2 + (a[1] + 1) / 2);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}