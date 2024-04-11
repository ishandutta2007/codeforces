#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MOD = 998244353;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) u -= MOD;
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) u += MOD;
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u); 
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

struct NTT {
    int base = 1;
    int maxBase = 0;
    int root = 2;
    vector<int> w = {0, 1};
    vector<int> rev = {0, 1};
    NTT() {
        int u = MOD - 1;
        while (u % 2 == 0) {
            maxBase++;
            u >>= 1;
        }
        while (power(root, 1 << maxBase) != 1 || power(root, 1 << (maxBase - 1)) == 1) root++;
    }
    void ensure(int curBase) {
        assert(curBase <= maxBase);
        if (curBase <= base) return;
        rev.resize(1 << curBase);
        for (int i = 0; i < (1 << curBase); i++) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (curBase - 1));
        }
        w.resize(1 << curBase);
        for (; base < curBase; base++) {
            int wc = power(root, 1 << (maxBase - base - 1));
            for (int i = 1 << (base - 1); i < (1 << base); i++) {
                w[i << 1] = w[i];
                w[i << 1 | 1] = mul(w[i], wc);
            }
        }
    }
    void fft(vector<int> &a) {
        int n = a.size();
        int curBase = 0;
        while ((1 << curBase) < n) curBase++;
        int shift = base - curBase;
        for (int i = 0; i < n; i++) {
            if (i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);
        }
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < k; i++) {
                for (int j = i; j < n; j += k * 2) {
                    int foo = a[j];
                    int bar = mul(a[j + k], w[i + k]);
                    a[j] = add(foo, bar);
                    a[j + k] = sub(foo, bar);
                }
            }
        }
    }
    vector<int> mult(vector<int> a, vector<int> b) {
        int nResult = a.size() + b.size() - 1;
        int curBase = 0;
        while ((1 << curBase) < nResult) curBase++;
        ensure(curBase);
        int n = 1 << curBase;
        a.resize(n), b.resize(n);
        fft(a);
        fft(b);
        int invN = inv(n);
        for (int i = 0; i < n; i++) {
            a[i] = mul(a[i], mul(b[i], invN));
        }
        reverse(a.begin() + 1, a.end());
        fft(a);
        a.resize(nResult);
        return a;
    }
} ntt;

int n, k, l;
int fac[N * 2], invFac[N * 2];

int comb(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fac[n], mul(invFac[n - k], invFac[k]));
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < N * 2; i++) {
        fac[i] = mul(fac[i - 1], i);
    }
    invFac[N * 2 - 1] = inv(fac[N * 2 - 1]);
    for (int i = N * 2 - 2; i >= 0; i--) {
        invFac[i] = mul(invFac[i + 1], i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> l;
    
    init();

    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = k; i <= n; i++) {
        a[i] = invFac[i];
    }
    for (int i = 0; i <= n; i++) {
        b[i] = invFac[i];
        if (i & 1) b[i] = sub(0, b[i]);
    }
    vector<int> c = ntt.mult(a, b);
    c.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        c[i] = mul(c[i], mul(fac[n], invFac[n - i]));
    }
    int pow2 = 1;
    int res = 0;
    for (int i = 1; i < c.size(); i++) {
        pow2 = mul(pow2, 2);
        int foo = mul(pow2, c[i]);
        foo = mul(foo, mul(fac[i], fac[i]));
        foo = mul(foo, invFac[2 * i + 1]);
        res = add(res, foo);
    }
    cout << mul(res, l) << endl;
    return 0;
}