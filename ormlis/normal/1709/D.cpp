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

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 1e5;


template<class T, class Fun = function<T(const T &, const T &)>>
struct SparseTable {
    vector<vector<T>> sp;
    Fun f;

    SparseTable(vector<T> &a, const Fun &g) : f(g) {
        int n = a.size();
        int lg = __lg(n) + 1;
        sp.resize(lg, vector<T>(n));
        rep(i, n) sp[0][i] = a[i];
        rep(j, lg - 1) {
            rep(i, n) {
                if (i + (1 << (j + 1)) > n) break;
                sp[j + 1][i] = f(sp[j][i], sp[j][i + (1 << j)]);
            }
        }
    }

    // [l, r)
    T get(int l, int r) {
        int k = __lg(r - l);
        return f(sp[k][l], sp[k][r - (1 << k)]);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(m);
    rep(i, m) cin >> a[i];
    SparseTable st(a, [&](const int &x, const int &y) {
        return max(x, y);
    });
    int q;
    cin >> q;
    rep(_, q) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        x1 += ((n - x1) / k) * k;
        x2 += ((n - x2) / k) * k;
        if (x1 != x2) {
            cout << "NO\n";
            continue;
        }
        if ((y1 - y2) % k) {
            cout << "NO\n";
            continue;
        }
        if (st.get(min(y1, y2) - 1, max(y1, y2)) >= x1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}