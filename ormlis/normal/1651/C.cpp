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
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ar<ll, 4> res = {INF, INF, INF, INF};
    rep(i, n) {
        res[0] = min(res[0], 1ll * abs(a[0] - b[i]));
        res[1] = min(res[1], 1ll * abs(a[n - 1] - b[i]));
        res[2] = min(res[2], 1ll * abs(b[0] - a[i]));
        res[3] = min(res[3], 1ll * abs(b[n - 1] - a[i]));
    }
    ll ans = INF;
    {
        ll cur = 0;
        cur += min(1ll * abs(a[0] - b[0]), res[0] + res[2]);
        cur += min(1ll * abs(a[n - 1] - b[n - 1]), res[1] + res[3]);
        ans = min(ans, cur);
    }
    {
        ll cur = 0;
        cur += min(1ll * abs(a[0] - b[n - 1]), res[0] + res[3]);
        cur += min(1ll * abs(a[n - 1] - b[0]), res[1] + res[2]);
        ans = min(ans, cur);
    }
    cout << ans << '\n';
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