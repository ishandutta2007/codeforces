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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = double;
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

const int maxN = 6e5;
vector<int> g[maxN];
const int md = 998244353;


int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

int psq[maxN];

void init() {
    int s = 31;
    for (int i = (1 << 23); i >= 1; i /= 2, s = mul(s, s)) {
        if (i < maxN) psq[i] = s;
    }
}

void fft(vector<int> &s, vector<int> &res, int n, int x, int ss = 0, int step = 1, int rs = 0) {
    if (n == 1) {
        res[rs] = s[ss];
        return;
    }
    fft(s, res, n / 2, mul(x, x), ss, step * 2, rs);
    fft(s, res, n / 2, mul(x, x), ss + step, step * 2, rs + n / 2);
    int c = 1;
    for (int i = rs; i < rs + n / 2; ++i) {
        auto a = res[i], b = res[i + n / 2];
        res[i] = add(a, mul(b, c));
        res[i + n / 2] = sub(a, mul(b, c));
        c = mul(c, x);
    }
}

vector<int> multiply(vector<int> &a, vector<int> &b) {
    vector<int> as(all(a)), bs(all(b));
    int n = 1;
    while (n < a.size() || n < b.size()) n *= 2;
    n *= 2;
    as.resize(n);
    bs.resize(n);
    int t = psq[n];
    vector<int> resa(n), resb(n);
    fft(as, resa, n, t);
    fft(bs, resb, n, t);
    range(i, n)resa[i] = mul(resa[i], resb[i]);
    t = rev(t);
    fft(resa, as, n, t);
    int rn = rev(n);
    range(i, n) as[i] = mul(as[i], rn);
    return as;
}

vector<int> have;
void dfs(int v, int p) {
    have.push_back((int)g[v].size());
    if (p != -1) have.back()--;
    if (have.back() == 0) have.pop_back();
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
}

void solve() {
    init();
    int n; cin >> n;
    rep(_, n - 1) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1);
    function<vector<int>(int, int)> solve = [&] (int l, int r) {
        if (l + 1 == r) {
            return vector<int>{1, have[l]};
        }
        auto L = solve(l, (l + r) / 2);
        auto R = solve((l + r) / 2, r);
        auto M = multiply(L, R);
        while(!M.empty() && M.back() == 0) M.pop_back();
        return M;
    };
    auto res = solve(0, (int)have.size());
    int f = 1;
    for(int i = 1; i < n; ++i) f = mul(f, i);
    int ans = mul(f, n);
    for(int i = 1; i < (int)res.size(); ++i) {
        if (i % 2 == 0) {
            ans = add(ans, mul(f, res[i]));
        } else {
            ans = sub(ans, mul(f, res[i]));
        }
        f = mul(f, rev(n - i));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(_, t) {
        solve();
    }
    return 0;
}