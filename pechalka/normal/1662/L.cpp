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
const int maxN = 5e3;
const int LG = 100;
const int md = 998244353; //1e9 + 7, 1e9 + 9

void solve() {
    int n, v; cin >> n >> v;
    vector<ll> t(n), a(n);
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> a[i];
    rep(i, n) t[i] *= v;
    vector<pair<ll, ll>> xy(n);
    rep(i, n) xy[i].first = t[i] + a[i];
    rep(i, n) xy[i].second = t[i] - a[i];
    sort(all(xy));
    vl res(n + 1, INF);
    for(auto &[x, y] : xy) {
        if (y < 0 || x < 0) continue;
        (*upper_bound(all(res), y)) = y;
    }
    cout << lower_bound(all(res), INF) - res.begin() << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}