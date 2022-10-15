#include <cstdio>

int ni() {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    int sg = 0;
    if (c == '-') {
        sg = 1;
        c = getchar();
    }   
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return sg ? -ret : ret;
}

long long nl() {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    int sg = 0;
    if (c == '-') {
        sg = 1;
        c = getchar();
    }   
    long long ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return sg ? -ret : ret;
}

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int dp[3234567];

int main() {    
    long long b = nl();
    long long a = nl();
    int k = ni();
    int f = 1;
    for (int i = 2; i <= k; i++) {
        f = lcm(f, i);
    }
    for (int i = 1; i < f; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 2; j <= k; j++) {
            int z = i % j;
            if (z > 0 && dp[i] > dp[i - z] + 1) dp[i] = dp[i - z] + 1;
        }
    }
    long long ans = 0;
    if (b - a > 3 * f) {
        ans = dp[b % f];
        b -= b % f;
        ans += (dp[f - 1] + 1) * ((b - a) / f);
        b -= (b - a) / f * f;
    }
    dp[0] = 0;
    int dd = b - a;
    for (int i = 1, z = (a + 1) % f; i <= dd; i++, z++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 2; j <= k; j++) {
            int q = z % j;
            if (q > 0 && i - q >= 0 && dp[i - q] + 1 < dp[i]) dp[i] = dp[i - q] + 1;
        }
    }
    printf("%I64d\n", dp[dd] + ans);
}