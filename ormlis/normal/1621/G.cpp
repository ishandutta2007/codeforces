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
const int maxN = 6e6 + 100;
const int LG = 20;


const int md = 1e9 + 7;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

struct fenwick {
    int n{};
    vector<int> fenw{};

    void build(int k) {
        n = k + 5;
        fenw.resize(n);
    }

    void upd(int i, int x) {
        for (; i < n; i = i | (i + 1)) fenw[i] = add(fenw[i], x);
    }

    int get(int i) {
        int res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res = add(res, fenw[i]);
        return res;
    }

    int get(int l, int r) {
        if (l > r) return 0;
        return sub(get(r), get(l - 1));
    }
};

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    {
        auto b = a;
        sort(all(b));
        b.resize(unique(all(b)) - b.begin());
        rep(i, n) {
            a[i] = lower_bound(all(b), a[i]) - b.begin();
            a[i]++;
        }
    }
    int sum_lens = 0;
    vi res;
    {
        fenwick f_len;
        f_len.build(n + 1);
        fenwick f_cnt;
        f_cnt.build(n + 1);
        f_cnt.upd(0, 1);
        for (auto &x : a) {
            int cur_cnt = f_cnt.get(x - 1);
            res.push_back(cur_cnt);
            f_cnt.upd(x, cur_cnt);
            int cur_len = f_len.get(x - 1);
            f_len.upd(x, add(cur_cnt, cur_len));
        }
        sum_lens = f_len.get(n);
    }
    vector<pair<int, int>> stk;
    for (int i = n - 1; i >= 0; --i) {
        if (stk.empty() || stk.back().first < a[i]) {
            stk.emplace_back(a[i], i);
        }
    }
    fenwick f_cnt;
    f_cnt.build(n + 5);
    int ans = sum_lens;
    for (int i = n - 1; i >= 0; --i) {
        int cntL = res[i];
        pair<int, int> tmp = {a[i] + 1, -1};
        int r = lower_bound(all(stk), tmp) - stk.begin();
        int cntR = 1;
        if (r != (int)stk.size()) {
            cntR = add(1, f_cnt.get(a[i] + 1, stk[r].first - 1));
            f_cnt.upd(a[i], cntR);
        }
        ans = sub(ans, mul(cntL, cntR));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}