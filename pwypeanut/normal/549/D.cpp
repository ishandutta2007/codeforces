#include <bits/stdc++.h>
using namespace std;

int N, M, coef[105][105], sum[105][105], rowsum[105];
char g[105][105];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%s", &g[i]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (g[i][j] == 'W') sum[i][j] = 1;
            else sum[i][j] = -1;
        }
    }
    coef[N-1][M-1] = 0;
    for (int i = N-1; i >= 0; i--) {
        if (i == N-1) coef[i][M-1] = sum[i][M-1];
        else coef[i][M-1] = (sum[i][M-1] - rowsum[M-1]);
        rowsum[M-1] += coef[i][M-1];
        for (int j = M-2; j >= 0; j--) {
            if (i == N-1) coef[i][j] = (sum[i][j] - sum[i][j+1]);
            else {
                int sum1 = 0;
                for (int k = j; k < M; k++) sum1 += rowsum[k];
                //if (i == 1 && j == 4) printf("hi %d\n", sum1);
                coef[i][j] = sum[i][j] - sum1;
            }
            rowsum[j] += coef[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (coef[i][j] != 0) ans++;
    printf("%d\n", ans);
}