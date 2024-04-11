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
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    map<int, int> lrow, lcol;
    rep(i, q) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        lrow[x] = i;
        lcol[y] = i;
    }
    vi have(q, 0);
    {
        int v = -1;
        if (lrow.size() == n) {
            v = q;
            for (auto &[a, b] : lrow) v = min(v, b);
        }
        for (auto &[_, b] : lcol) {
            if (b >= v) have[b] = 1;
        }
    }
    {
        int v = -1;
        if (lcol.size() == m) {
            v = q;
            for (auto &[a, b] : lcol) v = min(v, b);
        }
        for (auto &[_, b] : lrow) {
            if (b >= v) have[b] = 1;
        }
    }
    int ans = 1;
    rep(i, q) {
        if (have[i]) {
            ans = (1ll * ans * k) % 998244353;
        }
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