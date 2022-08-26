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

using int128 = __int128;
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
const int maxN = 6e5 + 10;
const int LG = 17;
const int md = 998244353;

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
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 6e5 + 5;
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


void solve() {
    int n;
    cin >> n;
    initF();
    init();

    vi b2;
    {
        vi A(n);
        for (int t = (n + 1) / 2; t < n; ++t) {
            A[t] = fact[t - 1];
        }
        vi B(n);
        rep(x, n) {
            B[x] = rfact[n - 1 - x];
        }
        auto C = multiply(A, B);
        b2.resize(n);
        for (int i = n; i < min((int) C.size(), n * 2 - 1); ++i) {
            b2[i - n + 1] = C[i];
        }
    }
    vi b1;
    {
        vi A(n);
        for (int t = (n + 1) / 2; t < n; ++t) {
            A[t] = mul(mul(fact[t - 1], fact[n - 1 - t]), rfact[t]);
        }
        vi B(n);
        rep(x, n) {
            B[x] = rfact[x];
        }
        auto C = multiply(A, B);
        b1.resize(n);
        // n - 1 - root
        for (int i = 0; i < (int) C.size(); ++i) {
            int root = n - 1 - i;
            if (root >= 0 && root < n) {
                b1[root] = C[i];
            }
        }
    }
    rep(root, n) {
        if (root * 2 > n) {
            cout << "0 ";
            continue;
        }
        // dp[take][big]
        // (x * big + (k - big))
        // a = k - big
        // b = big
        // (a, b) -> (a + 1, b) == *a
        // (a, b) -> (a, b + 1) == *b
        int ml = fact[root];
        //for (int i = 1; i <= root; ++i) ml = mul(ml, i);
        int ans = mul(fact[n - 1], rfact[root]);
        //for (int i = root + 1; i < n; ++i) ans = mul(ans, i);
        // sum t = (n + 1) / 2 .. n
        //
        int bad1 = b1[root];
        int bad2 = b2[root];
        // a-b, (a-1)! * ~(b)!
/*
        for (int t = (n + 1) / 2; t < n; ++t) {
            if (n - 1 - t >= root) {
                // 1 case:
                // f(t) = (t-1)!(n-1-t)!/(t!)
                // g(root) = (n - 1 - root)!/root!
                // kek = 1/(n-1-root-t)!
                int r = fact[t - 1];
                r = mul(r, fact[n - 1 - t]);
                r = mul(r, mul(rfact[n - 1 - root - t], rfact[t]));
                bad1 = add(bad1, r);
            }
            if (root != 0) {
                // 2 case:
                // f(t) = (t-1)!
                // g(root) = (n-1-root)!/(root - 1)!
                // kek = 1/(t - root)!
                int r = fact[t - 1];
                r = mul(r, rfact[t - root]);
                bad2 = add(bad2, r);
            }
        }
        */
        bad1 = mul(bad1, mul(fact[n - 1 - root], rfact[root]));
        bad2 = mul(bad2, mul(fact[n - 1 - root], rfact[root - 1]));
        ans = sub(ans, bad1);
        ans = sub(ans, bad2);
        cout << mul(ml, ans) << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
//     cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}