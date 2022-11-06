#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100 + 5;

int T, N, M;
int b[MAX_N][MAX_N], bl[MAX_N], br[MAX_N];
int a[MAX_N][MAX_N];

int main() {
    scanf("%d", &T);
    for (; T --; ) {
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= M; j ++) {
                scanf("%d", &b[i][j]);
            }
            sort(b[i] + 1, b[i] + 1 + M);
            bl[i] = 1, br[i] = M;
        }
        for (int j = 1; j <= M; j ++) {
            int t = 2e9, k = 0;
            for (int i = 1; i <= N; i ++) {
                if (t > b[i][bl[i]]) {
                    t = b[i][bl[i]], k = i;
                }
            }
            for (int i = 1; i <= N; i ++) {
                a[i][j] = i == k ? b[i][bl[i] ++] : b[i][br[i] --];
            }
        }
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= M; j ++) {
                printf("%d%c", a[i][j], j < M ? ' ' : '\n');
            }
        }
    }
    return 0;
}