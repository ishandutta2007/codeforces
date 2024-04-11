#include <bits/stdc++.h>

using namespace std;

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
    int root = 31;
    int maxBase = 23;

    void fft(vector<int> &a) {
        int n = a.size();
        int logN = round(log2(n));
        for (int i = 0; i < n; i++) {
            int u = 0;
            for (int j = 0; j < logN; j++) {
                u |= ((i >> j) & 1) << (logN - j - 1);
            }
            if (u < i) swap(a[u], a[i]);
        }
        for (int k = 1; k < n; k <<= 1) {
            int w = 1, wDelta = power(root, (1 << maxBase) / k / 2);
            for (int i = 0; i < k; i++, w = mul(w, wDelta)) {
                for (int j = i; j < n; j += k * 2) {
                    int foo = a[j];
                    int bar = mul(a[j + k], w);
                    a[j] = add(foo, bar);
                    a[j + k] = sub(foo, bar);
                }
            }
        }
    }

    vector<int> mult(vector<int> a, vector<int> b, int keep = 1) {
        int sz = a.size() + b.size() - 1;
        int oldSize = a.size();
        int n = 1;
        while (n < sz) n <<= 1;
        a.resize(n, 0);
        b.resize(n, 0);
        fft(a);
        fft(b);
        int invN = inv(n);
        for (int i = 0; i < n; i++) a[i] = mul(a[i], mul(b[i], invN));
        reverse(a.begin() + 1, a.end());
        fft(a);
        a.resize(sz);
        if (keep) a.resize(oldSize);
        return a;
    }
} ntt;

struct Triple {
    vector<int> a, b, c;
    Triple(int k) {
        a.resize(k, 0);
        b.resize(k, 0);
        c.resize(k, 0);
    }

    int get() {
        int res = 0;
        for (int u : a) res = add(res, u);
        return res;
    }
};

Triple update(const Triple &u, const Triple &v) {
    vector<int> aa = ntt.mult(u.a, v.a);
    vector<int> ab = ntt.mult(u.a, v.b);
    vector<int> bb = ntt.mult(u.b, v.b);
    vector<int> bc = ntt.mult(u.b, v.c);
    vector<int> cc = ntt.mult(u.c, v.c);
    Triple res(aa.size());
    for (int i = 0; i < aa.size(); i++) {
        res.a[i] = aa[i];
        res.b[i] = ab[i];
        res.c[i] = bb[i];
        if (i > 0) {
            res.a[i] = add(res.a[i], bb[i - 1]);
            res.b[i] = add(res.b[i], bc[i - 1]);    
            res.c[i] = add(res.c[i], cc[i - 1]);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    Triple res(k + 1), u(k + 1);
    res.a[0] = 1;
    u.a[0] = u.a[1] = u.b[0] = 1;
    while (n) {
        cerr << n << endl;
        if (n & 1) res = update(res, u);
        u = update(u, u);
        n >>= 1;
    }
    for (int i = 1; i <= k; i++) {
        cout << res.a[i] << ' ';
    }
    cout << endl;
    return 0;
}