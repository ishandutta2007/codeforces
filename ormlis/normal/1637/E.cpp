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
const int maxN = 1e5 + 30;
const int LG = 19;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    map<int, vector<int>> tocnt;
    rep(i, n) {
        int x; cin >> x;
        cnt[x]++;
    }
    for(auto &[x, cx] : cnt) tocnt[cx].push_back(x);
    map<int, vi> g;
    rep(_, m) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll ans = -INF;
    for(auto [x, cx] : cnt) {
        auto v = g[x];
        sort(all(v));
        for(auto &[cy, vy] : tocnt) {
            for(int j = (int)vy.size() - 1; j >= 0; --j) {
                int y = vy[j];
                int i = lower_bound(all(v), y) - v.begin();
                if (y == x || (i != (int)v.size() && v[i] == y)) continue;
                ans = max(ans, 1ll * (cx + cy) * (x + y));
                break;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}