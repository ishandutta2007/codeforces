#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


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

const int maxF = 2e5 + 5;
int fact[maxF];
int rfact[maxF];

void init() {
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

void initFFT() {
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

int stupid(int a, int b, int d) {
    int res = C(a + b, b + d);
    int ans = 0;
    if (d >= 0) {
        for (int i = 0; i <= b; ++i) {
            ans = add(ans, mul(C(b, i), C(a, i + d)));
        }
    } else {
        for (int i = 0; i <= a; ++i) {
            ans = add(ans, mul(C(a, i), C(b, i - d)));
        }
    }
    if (ans != res) {
        cout << "kek\n";
    }
}

void solve() {
    init();
    initFFT();
    int n;
    cin >> n;
    int sz = 1;
    vector<int> cur(sz, 1);
    range(_, n) {
        int a, b;
        cin >> a >> b;
        int nxt = sz + a - b;
        int S = max(nxt, sz) + 2;
        vector<int> cnt(S * 2 + 2);
        int mid = S;
        for (int j = -S; j <= S; ++j) {
            cnt[j + mid] = C(a + b, b + j);
        }
        auto kek = multiply(cur, cnt);
        vector<int> res2(nxt);
        range(j, nxt) res2[j] = kek[j + mid];
        swap(res2, cur);
        sz = nxt;
    }
    int ans = 0;
    range(i, sz) ans = add(ans, cur[i]);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}