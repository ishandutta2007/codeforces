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

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 2e6 + 10;


const int md = 998244353; //1e9 + 9;

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
    int r = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) r = mul(r, a);
    return r;
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 3e5 + 20;
int fact[maxF];
int rfact[maxF];

void initF() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
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

const int N = 3e5;
int dp[N + 1];

void precalc() {
    vi A(N + 1);
    int rv2 = rev(2);
    int t = 1;
    for (int i = 0; i * 2 <= N; ++i) {
        A[i * 2] = mul(rfact[i], t);
        t = mul(t, rv2);
    }
    vi B(N + 1);
    rep(i, N + 1) B[i] = rfact[i];
    auto C = multiply(A, B);
    C.resize(N + 1);
    for (int i = 0; i <= N; ++i) {
        dp[i] = mul(C[i], fact[i]);
    }
}


void solve() {
    int n;
    cin >> n;
    int ans = 0;

    auto calc = [](int n) {
        return dp[n];
    };
    for (int cnt4 = 0; cnt4 * 4 <= n; ++cnt4) {
        int r = C(n - cnt4 * 2, cnt4 * 2);
        r = mul(r, fact[cnt4 * 2]);
        r = mul(r, rfact[cnt4]);
        r = mul(r, calc(n - cnt4 * 4));
        ans = add(ans, r);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    initF();
    init();
    precalc();
    range(i, t) {
        solve();
    }
    return 0;
}