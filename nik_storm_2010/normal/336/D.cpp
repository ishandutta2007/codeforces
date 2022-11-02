#include<cstdio>

using namespace std;
const int mod = 1000000007;

long long fact[200000 + 10];

long long power(long long x, long long y) {
    if (y == 1) return x;
    long long c = power(x, y >> 1);
    if (y & 1) return ((((c * c) % mod) * x) % mod); else return ((c * c) % mod);
}

int main() {
    int n, m, g;
    scanf("%d %d %d", &n, &m, &g);
    long long k0 = 0, k1 =0;
    if (m == 0) {
        if (n & 1) k0++; else k1++;
    }
    else {
        fact[0] = 1;
        for (int i = 1; i <= n + m; i++) fact[i] = (fact[i - 1] * i) % mod;
        for (int i = 0; i <= n; i++) {
            int x = n + m - i - 1;
            int y = n - i;
            long long res = (fact[x] * power((fact[x - y] * fact[y]) % mod, mod - 2)) % mod;
            if (i == n && m == 1) {
                if (i & 1) k0 = (k0 + 1) % mod; else k1 = (k1 + 1) % mod;
            }
            else {
                if (i & 1) k1 = (k1 + res) % mod; else k0 = (k0 + res) % mod;
            }
        }
    }
    if (g == 0) printf("%d", k0); else printf("%d", k1);
    return 0;
}