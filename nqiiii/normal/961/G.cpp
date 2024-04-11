#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007, maxN = 200000;

int Add(int x, int y) {
    x += y; return x < mod ? x : x - mod;
}

int Dec(int x, int y) {
    x -= y; return x < 0 ? x + mod : x;
}

int Mul(int x, int y) {
    return 1ll * x * y % mod;
}

int Fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = Mul(ans, x);
        y >>= 1; x = Mul(x, x);
    }
    return ans;
}

int n, k, inv[maxN + 10], fac[maxN + 10], invFac[maxN + 10], sum;

void PreWork() {
    fac[0] = invFac[0] = 1;
    for (int i = 1; i <= maxN; ++i) {
        inv[i] = i == 1 ? 1 : Dec(0, Mul(mod / i, inv[mod % i]));
        fac[i] = Mul(fac[i - 1], i);
        invFac[i] = Mul(invFac[i - 1], inv[i]);
    }
}

int Choose(int n, int m) {
    return Mul(fac[n], Mul(invFac[m], invFac[n - m]));
}

int Stirling2(int n, int m) {
    int ans = 0;
    for (int i = 0; i <= m; ++i) {
        if (i & 1) ans = Dec(ans, Mul(Choose(m, i), Fpow(m - i, n)));
        else ans = Add(ans, Mul(Choose(m, i), Fpow(m - i, n)));
    }
    return Mul(ans, invFac[m]);
}

int main() {
    PreWork();
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x); sum = Add(sum, x);
    }
    printf("%d", Mul(sum, Add(Stirling2(n, k), Mul(n - 1, Stirling2(n - 1, k)))));
}