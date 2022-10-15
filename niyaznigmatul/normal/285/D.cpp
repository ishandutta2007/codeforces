#include <cstdio>
#include <algorithm>

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

//int p[1234567], was[1234567];

const int MOD = 1000000007;

int ans[] = {1, 3, 15, 133, 2025, 37851, 1030367, 36362925, 1606008513 % MOD, 87656896891 % MOD, 5778121715415 % MOD, 452794797220965 % MOD, 41609568918940625 % MOD};

int main() {
    int n = ni();
    if ((n & 1) == 0) puts("0"); else {
        long long z = ans[n >> 1];
        for (int i = 2; i <= n; i++) {
            z = (z * i) % MOD;
        }
        printf("%d\n", (int) z);
    }
}