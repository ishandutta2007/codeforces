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
const int maxN = 1e5 + 30;
const int LG = 19;

bitset<(1 << 12)> val[maxN];

void solve() {
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> a(k, vi(n));
    rep(i, k) rep(j, n) cin >> a[i][j];
    rep(i, k) {
        rep(mask, (1 << 12)) {
            val[i][mask] = ((mask >> i) & 1);
        }
    }
    vector<vector<int>> ord(n, vi(k));
    rep(i, n) {
        iota(all(ord[i]), 0);
        sort(all(ord[i]), [&] (const int &x, const int &y) {
            return a[x][i] < a[y][i];
        });
        ord[i][0] = (1 << ord[i][0]);
        for(int j = 1; j < k; ++j) ord[i][j] = (1 << ord[i][j]) | ord[i][j - 1];
    }
    int R = k;
    rep(_, q) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            x--;
            y--;
            val[R++] = val[x] & val[y];
        } else if (t == 2) {
            int x, y; cin >> x >> y;
            x--;
            y--;
            val[R++] = val[x] | val[y];
        } else {
            int x, y; cin >> x >> y;
            x--;
            y--;
            for(int i = 0; i < k; ++i) {
                if (val[x][ord[y][i]]) {
                    int w = ord[y][i];
                    if (i != 0) w ^= ord[y][i - 1];
                    int j = __builtin_ctz(w);
                    cout << a[j][y] << '\n';
                    break;
                }
            }
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}