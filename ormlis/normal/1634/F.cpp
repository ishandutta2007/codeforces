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
const int maxN = 1e6 + 30;
const int LG = 100;

void solve() {
    int n, q, md; cin >> n >> q >> md;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    for(int i = n - 1; i >= 1; --i) {
        int x = a[i];
        x -= a[i - 1];
        if (i > 1) x -= a[i - 2];
        x %= md;
        x += md;
        x %= md;
        a[i] = x;
    }
    for(int i = n - 1; i >= 1; --i) {
        int x = b[i];
        x -= b[i - 1];
        if (i > 1) x -= b[i - 2];
        x %= md;
        x += md;
        x %= md;
        b[i] = x;
    }
    int cnt = 0;
    rep(i, n) if (a[i] == b[i]) cnt++;
    vector<int> eq(n);
    rep(i, n) if (a[i] == b[i]) eq[i] = 1;
    auto check = [&] (int i) {
        if (i < 0 || i >= n) return;
        cnt -= eq[i];
        if (a[i] == b[i]) eq[i] = 1;
        else eq[i] = 0;
        cnt += eq[i];
    };
    vector<int> f(n + 4);
    f[1] = f[2] = (1 % md);
    for(int i = 3; i < f.size(); ++i) f[i] = (f[i - 1] + f[i - 2]) % md;
    rep(_, q) {
        char c; cin >> c;
        int l, r; cin >> l >> r;
        if (c == 'B') {
            swap(a, b);
        }
        l--;
        r--;
        a[l] = (a[l] + 1) % md;
        check(l);
        if (r + 1 < n) {
            a[r + 1] -= f[r - l + 2];
            a[r + 1] += md;
            a[r + 1] %= md;
            check(r + 1);
        }
        if (r + 2 < n) {
            a[r + 2] -= f[r - l + 1];
            a[r + 2] += md;
            a[r + 2] %= md;
            check(r + 2);
        }
        if (c == 'B') {
            swap(a, b);
        }
        if (cnt == n) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}