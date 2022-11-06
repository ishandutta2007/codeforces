#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000000 + 5;
const int P = 998244353;

int N;
int f[MAX_N], sf[MAX_N];
int d[MAX_N];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        for (int j = i + i; j <= N; j += i) {
            d[j] ++;
        }
    }
    f[0] = sf[0] = 1;
    for (int i = 1; i <= N; i ++) {
        f[i] = sf[i - 1] + d[i];
        f[i] -= f[i] >= P ? P : 0;
        sf[i] = sf[i - 1] + f[i];
        sf[i] -= sf[i] >= P ? P : 0;
    }
    printf("%d\n", f[N]);
    return 0;
}