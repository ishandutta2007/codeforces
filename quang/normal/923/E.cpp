#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MOD = 998244353;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, long long v) {
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
    const static int ROOT = 31;
    int maxBase = 0;

    NTT() {
        int u = MOD - 1;
        while (u % 2 == 0) {
            u /= 2;
            maxBase++;
        }
    }

    void fft(vector<int> &u) {
        int n = u.size();
        int lg = round(log2(n));
        for (int i = 0; i < n; i++) {
            int j = 0;
            for (int k = 0; k < lg; k++) {
                if ((i >> k) & 1) {
                    j |= (1 << (lg - k - 1));
                }
            }
            if (i < j) swap(u[i], u[j]);
        }
        for (int k = 1; k < n; k <<= 1) {
            int w = 1, wDelta = power(ROOT, (1 << maxBase) / k / 2);
            for (int i = 0; i < k; i++) {
                for (int j = i; j < n; j += 2 * k) {
                    int foo = u[j];
                    int bar = mul(w, u[j + k]);
                    u[j] = add(foo, bar);
                    u[j + k] = sub(foo, bar);
                }
                w = mul(w, wDelta);
            }
        }
    }

    vector<int> mult(vector<int> a, vector<int> b) {
        int nRes= a.size() + b.size() - 1;
        int n = 1;
        while (n < nRes) n <<= 1;
        a.resize(n, 0);
        b.resize(n, 0);
        fft(a);
        fft(b);
        int invN = inv(n);
        for (int i = 0; i < n; i++) {
            a[i] = mul(a[i], mul(b[i], invN));
        }
        reverse(a.begin() + 1, a.end());
        fft(a);
        a.resize(nRes);
        return a;
    }
} ntt;

int fac[N], invFac[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long m;
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = mul(fac[i - 1], i);
    }
    invFac[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        invFac[i] = mul(invFac[i + 1], i + 1);
    }

    cin >> n >> m;
    vector<int> a(n + 1);
    for (int &u : a) {
        cin >> u;
    }
    for (int i = 0; i < a.size(); i++) {
        a[i] = mul(a[i], fac[i]);
    }

    vector<int> b(n + 1);
    for (int i = 0; i < b.size(); i++) {
        b[i] = invFac[i];
    }
    reverse(a.begin(), a.end());

    vector<int> c = ntt.mult(a, b);
    c.resize(n + 1);
    reverse(c.begin(), c.end());

    for (int i = 0; i < c.size(); i++) {
        c[i] = mul(c[i], invFac[i]);
    }
    
    for (int i = 0; i < c.size(); i++) {
        c[i] = mul(c[i], inv(power(i + 1, m)));
    }


    for (int i = 0; i < c.size(); i++) {
        c[i] = mul(c[i], fac[i]);
        if (i & 1) c[i] = sub(0, c[i]);
    }
    reverse(c.begin(), c.end());

    vector<int> d = ntt.mult(c, b);
    d.resize(n + 1);
    reverse(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++) {
        d[i] = mul(d[i], invFac[i]);
        if (i & 1) d[i] = sub(0, d[i]);
    }
    for (int u : d) {
        cout << u << ' ';
    }
    cout << endl;
    return 0;
}