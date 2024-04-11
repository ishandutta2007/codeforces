#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N, A[300005], fac[500005];

int qexp(int b, int p) {
    if (p == 0) return 1;
    else if (p == 1) return b % MOD;
    else if (p % 2 == 0) {
        long long a = qexp(b, p/2);
        a *= a;
        a %= MOD;
        return a;
    } else {
        long long a = qexp(b, p/2);
        a *= a;
        a %= MOD;
        a *= b;
        a %= MOD;
        return a;
    }
}

int choose(int n, int k) {
    if (k < 0 || k > n) return 0;
    long long ans = fac[n];
    ans *= qexp(fac[k], MOD - 2);
    ans %= MOD;
    ans *= qexp(fac[n-k], MOD - 2);
    ans %= MOD;
    return ans;
}

int main() {
    long long ans = 1;
    fac[0] = 1;
    for (int i = 1; i < 500000; i++) {
        ans *= i;
        ans %= MOD;
        fac[i] = ans;
    }
    scanf("%d", &N);
    for (int i = 0; i <= N; i++) scanf("%d", &A[i]);
    long long rans = 0;
    for (int i = 0; i <= N; i++) {
        rans += choose(i+A[i], i+1);
        rans %= MOD;
    }
    printf("%lld\n", rans);
}