#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100 + 5;
const int P = 998244353;

int N, al[MAX_N], ar[MAX_N];
int A, av[MAX_N];
int ans0, ans1, inv[MAX_N];
int f[MAX_N][MAX_N];

int power_mod(int a, int b) {
    int c = 1;
    while (b) {
        if (b & 1) {
            c = 1ll * c * a % P;
        }
        a = 1ll * a * a % P;
        b >>= 1;
    }
    return c;
}

int main() {
    scanf("%d", &N);
    ans0 = 1;
    for (int i = 1; i <= N; i ++) {
        scanf("%d%d", &al[i], &ar[i]);
        ar[i] ++;
        ans0 = 1ll * ans0 * (ar[i] - al[i]) % P;
    }
    // printf("ans0=%d\n", ans0);
    ans0 = power_mod(ans0, P - 2);
    for (int i = 2; i <= N; i ++) {
        ar[i] = min(ar[i], ar[i - 1]);
    }
    for (int i = N - 1; i >= 1; i --) {
        al[i] = max(al[i], al[i + 1]);
    }
    for (int i = 1; i <= N; i ++) {
        av[i * 2 - 1] = al[i];
        av[i * 2] = ar[i];
    }
    sort(av + 1, av + 1 + N + N);
    A = unique(av + 1, av + 1 + N + N) - av - 1;
    // for (int i = 1; i <= A; i ++) {
    //     printf("av[%d]=%d\n", i, av[i]);
    // }
    for (int i = 1; i <= N; i ++) {
        al[i] = lower_bound(av + 1, av + 1 + A, al[i]) - av;
        ar[i] = lower_bound(av + 1, av + 1 + A, ar[i]) - av;
        // printf("i=%d,al=%d,ar=%d\n", i, al[i], ar[i]);
    }
    inv[1] = 1;
    for (int i = 2; i <= N; i ++) {
        inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
    }
    for (int j = 1; j <= A; j ++) {
        f[0][j] = 1;
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = al[i]; j < ar[i]; j ++) {
            int m = av[j + 1] - av[j], c = 1;
            for (int ii = i - 1; ii >= 0; ii --) {
                c = 1ll * c * (m + i - ii - 1) % P * inv[i - ii] % P;
                f[i][j] = (f[i][j] + 1ll * f[ii][j + 1] * c) % P;
                // printf("i=%d,j=%d,ii=%d,sf[ii][j+1]=%d,c=%d\n", i, j, ii, f[ii][j + 1], c);
                if (ar[ii] <= j || al[ii] > j) {
                    break;
                }
            }
            // printf("f[%d][%d]=%d\n", i, j, f[i][j]);
        }
        for (int j = A - 1; j >= 1; j --) {
            f[i][j] = (f[i][j] + f[i][j + 1]) % P;
        }
    }
    ans1 = f[N][1];
    // printf("ans1=%d\n", ans1);
    ans1 = 1ll * ans1 * ans0 % P;
    printf("%d\n", ans1);
    return 0;
}