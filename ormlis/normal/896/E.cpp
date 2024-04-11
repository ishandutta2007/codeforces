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
const int maxN = 5e4 + 5;
const int LG = 19;

struct fenwick {
    int n{};
    vector<int> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, int x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    int get(int i) {
        int res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    int get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

const int K = 500;
const int LGK = 10;
const int B = 500;

struct Block {
    vector<pair<int, int>> a;
    vector<int> ch;
    int sz;
    fenwick f;

    void init(vector<int> &vals) {
        rep(i, (int) vals.size()) {
            a.emplace_back(vals[i], i);
        }
        f.build(vals.size());
        sz = vals.size();
        ch.resize(sz + 1);
        sort(all(a));
    }

    void rebuild(int x) {
        rep(i, sz) {
            a[i].first += ch[i];
            if (a[i].first > x) a[i].first -= x;
            ch[i + 1] += ch[i];
        }
        ch.assign(sz + 1, 0);
        sort(all(a));
        f.fenw.assign(sz, 0);
    }

    int get_lower_bound(int x) {
        int i = -1;
        int need = x;
        for (int j = LGK - 1; j >= 0; --j) {
            int t = i + (int) (1 << j);
            if (t >= sz || a[t].first + f.fenw[t] >= need) continue;
            need -= f.fenw[t];
            i = t;
        }
        i++;
        return i;
    }

    void upd_all(int x) {
        int i = get_lower_bound(x + 1);
        if (i == sz) return;
        int val = a[i].first + f.get(i);
        assert(val > x);
        if (val <= 2 * x) {
            rebuild(x);
            return;
        }
        f.upd(i, -x);
        ch[i] -= x;
    }

    void upd(int L, int R, int x) {
        L = max(L, 0);
        R = min(R, sz);
        if (L >= R) return;
        if (L == 0 && R == sz) {
            upd_all(x);
            return;
        }
        rep(i, sz) {
            a[i].first += ch[i];
            if (a[i].first > x && a[i].second >= L && a[i].second < R) a[i].first -= x;
            ch[i + 1] += ch[i];
        }
        ch.assign(sz + 1, 0);
        sort(all(a));
        f.fenw.assign(sz, 0);
    }

    int get_all(int x) {
        int i = get_lower_bound(x);
        int j = get_lower_bound(x + 1);
        return j - i;
    }

    int get(int L, int R, int x) {
        L = max(L, 0);
        R = min(R, sz);
        if (L >= R) return 0;
        if (L == 0 && R == sz) {
            return get_all(x);
        }
        rebuild(INFi);
        int ans = 0;
        rep(i, sz) {
            if (a[i].first == x && L <= a[i].second && a[i].second < R) ans++;
        }
        return ans;
    }
};

Block b[B];

void solve() {
    int n, m; cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    for(int i = 0; i * K < n; ++i) {
        int L = i * K;
        int R = min(L + K, n);
        vector<int> vals;
        for(int j = L; j < R; ++j) vals.push_back(a[j]);
        b[i].init(vals);
    }
    rep(_, m) {
        int t; cin >> t;
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        int ans = 0;
        for(int i = 0; i * K < n; ++i) {
            int L = i * K;
            if (t == 1) {
                b[i].upd(l - L, r - L, x);
            } else {
                ans += b[i].get(l - L, r - L, x);
            }
        }
        if (t == 2) cout << ans << '\n';
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