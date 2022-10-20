#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    }
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) {
        u += MOD;
    }
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) {
            res = mul(res, u);
        }
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

const int N = 1000010;

int n;
int fac[N];

int c(int k, int n) {
    if (k > n) {
        return 0;
    }
    int foo = mul(fac[k], fac[n - k]);
    return mul(fac[n], inv(foo));
}

int main() {
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = mul(fac[i - 1], i);
    }
    int res1 = 0;
    for (int i = 1; i <= n; i++) {
        int x = power(3, i);
        int y = power(power(3, n), n - i);
        y = mul(x, y);
        y = mul(y, c(i, n));
        if (i % 2 == 0) {
            y = sub(0, y);
        }
        res1 = add(res1, y);
    }
    res1 = add(res1, res1);
    int res2 = 0;
    for (int i = 0; i < n; i++) {
        int x = power(3, i);
        int y = power(sub(1, x), n);
        x = power(x, n);
        if (n % 2 == 0) {
            y = sub(y, x);
        } else {
            y = add(y, x);
        }
        y = mul(y, c(i, n));
        if (i % 2 == 0) {
            y = sub(0, y);
        }
        res2 = add(res2, y);
    }
    res2 = mul(res2, 3);
    // cout << res1 << " " << res2 << endl;
    printf("%d\n", add(res1, res2));
    return 0;
}