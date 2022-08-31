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

void solve() {
    int n, w, h; cin >> n >> w >> h;
    vi g(n), p(n), t(n);
    map<int, vector<int>> mp;
    rep(i, n) {
        cin >> g[i] >> p[i] >> t[i];
        g[i]--;
        mp[p[i] - t[i]].push_back(i);
    }
    vpi ans(n);
    for(auto &[_, a] : mp) {
        vi ord1 = a;
        vi ord2 = a;
        sort(all(ord1), [&] (const int &i, const int &j) {
            if (g[i] != g[j]) return g[i] == 1;
            if (g[i] == 1) {
                return p[i] > p[j];
            } else {
                return p[i] < p[j];
            }
        });
        sort(all(ord2), [&] (const int &i, const int &j) {
            if (g[i] != g[j]) return g[i] == 0;
            if (g[i] == 1) {
                return p[i] > p[j];
            } else {
                return p[i] < p[j];
            }
        });
        rep(e, (int)a.size()) {
            int i = ord1[e];
            int j = ord2[e];
            if (g[j] == 1) {
                ans[i] = {w, p[j]};
            } else {
                ans[i] = {p[j], h};
            }
        }
    }
    rep(i, n) cout << ans[i].first << ' ' << ans[i].second << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}