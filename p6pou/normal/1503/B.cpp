#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100 + 5;

int N;
int a[MAX_N][MAX_N];
int n[5], p[5][MAX_N * MAX_N];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            int t = (i + j & 1) + 1;
            p[t][++ n[t]] = i << 10 | j;
        }
    }
    for (int i = 1, t, x; i <= N * N; i ++) {
        scanf("%d", &t);
        t = n[1] && t != 1 ? 1 : n[2] && t != 2 ? 2 : 3;
        x = t <= 2 ? p[t][n[t] --] : n[1] ? p[1][n[1] --] : p[2][n[2] --];
        printf("%d %d %d\n", t, x >> 10, x & 1023);
        fflush(stdout);
    }
    return 0;
}