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

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 2e5 + 10;

void solve() {
    int n, m; cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi b(n - 1);
    ll ans = 1ll * n * (n + 1) / 2;
    auto upd = [&] (int i, int x) {
        x = min(x, 1);
        if (b[i] == x) return;
        if (x) {
            ans += 1ll * (i + 1) * (n - i - 1);
        } else {
            ans -= 1ll * (i + 1) * (n - i - 1);
        }
        b[i] = x;
    };
    rep(i, n - 1) upd(i, a[i] ^ a[i + 1]);
    rep(_, m) {
        int i, x; cin >> i >> x;
        i--;
        a[i] = x;
        if (i) upd(i - 1, a[i] ^ a[i - 1]);
        if (i + 1 < n) upd(i, a[i] ^ a[i + 1]);
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}