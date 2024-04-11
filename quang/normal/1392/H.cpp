#include <bits/stdc++.h>

using namespace std;

const int N = 4000010;
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

int n, m;
int fac[N], invFac[N];
int f[N];

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fac[n], mul(invFac[k], invFac[n - k]));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    //init
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = mul(fac[i - 1], i);
    invFac[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) invFac[i] = mul(invFac[i + 1], i + 1);
    f[n] = 0;

    int sum = mul(fac[n + m - n - 1], invFac[n - n]);
    int sumCum = sum;
    int sumF = 0;
    for (int i = n - 1; i >= 0; i--) {
        int A = mul(m, mul(fac[n - i], mul(fac[i], invFac[n + m])));
        int B1 = mul(C(n + m, i), sumF);
        sum = add(sum, mul(fac[n + m - i - 1], invFac[n - i]));
        sumCum = add(sumCum, sum);
        int B2 = mul(C(n + m + 1, i), sumCum);
        int LHS = mul(mul(fac[n + m - i - 1], invFac[n - i]), C(n + m, i));

        B1 = mul(B1, A);
        B2 = mul(B2, A);
        LHS = mul(LHS, A);
        f[i] = mul(add(B1, B2), inv(sub(1, LHS)));

        sumF = add(sumF, mul(mul(fac[n + m - i - 1], invFac[n - i]), f[i]));
    }
    cout << f[0] << endl;
    return 0;
}