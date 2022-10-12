#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
const int MOD = 1000000007;

int power(int a, int n, int mod) {
    int ret = 1, carry = a;

    while (n > 0) {
        if (n & 1) ret = 1LL * ret * carry % mod;
        carry = 1LL * carry * carry % mod;
        n >>= 1;
    }

    return ret;
}

int primeDivisor[N], fact[N], inv[N];

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    else return 1LL * fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
    primeDivisor[1] = 1;
    fact[0] = fact[1] = inv[1] = inv[0] = 1;
    for (int i = 2; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
        inv[i] = power(fact[i], MOD - 2, MOD);

        if (primeDivisor[i] > 0) continue;
        for (int j = i; j < N; j += i)
            primeDivisor[j] = i;
    }

    int q;
    scanf ("%d", &q);

    while (q--) {
        int r, n;
        scanf ("%d %d", &r, &n);

        int ans = 1;

        while (n > 1) {
            int pr = primeDivisor[n];
            int k = 0;

            while (n % pr == 0)
                n /= pr, k++;

            ans = 1LL * ans * ((C(k + r - 1, r - 1) + 2LL * C(k + r - 1, r) % MOD) % MOD) % MOD;
        }

        printf ("%d\n", ans);
    }

    return 0;
}