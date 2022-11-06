#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100 + 5;

int T, N, a[MAX_N];
int b[MAX_N][MAX_N], vis[MAX_N];
int f[MAX_N];

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
            a[i] = min(a[i], N + 1);
        }
        for (int l = N; l >= 1; l --) {
            for (int i = 0; i <= N; i ++) {
                vis[i] = 0;
            }
            for (int r = l, t = 0; r <= N; r ++) {
                vis[a[r]] = 1;
                for (; vis[t]; t ++);
                b[l][r] = t;
            }
        }
        int ans = 0;
        for (int l = 1; l <= N; l ++) {
            f[l - 1] = 0;
            for (int i = l; i <= N; i ++) {
                f[i] = 0;
                for (int j = i - 1; j >= l - 1; j --) {
                    f[i] = max(f[i], f[j] + 1 + b[j + 1][i]);
                }
                ans += f[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}