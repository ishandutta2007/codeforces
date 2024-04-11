#include <bits/stdc++.h>
using namespace std;

int dp[35][35][50], T;

int f(int h, int w, int k) {
    if (k == 0) return 0;
    if (h * w == k) return 0;
    if (dp[h][w][k] != -1) return dp[h][w][k];
    int mini = 1000000;
    for (int i = 1; i < h; i++) {
        for (int j = 0; j <= k; j++) {
            mini = min(mini, f(i, w, j) + f(h-i, w, k-j) + w * w);
        }
    }
    for (int i = 1; i < w; i++) {
        for (int j = 0; j <= k; j++) {
            mini = min(mini, f(h, i, j) + f(h, w-i, k-j) + h * h);
        }
    }
    return dp[h][w][k] = mini;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &T);
    while (T--) {
        int h, w, k;
        scanf("%d%d%d", &h, &w, &k);
        printf("%d\n", f(h, w, k));
    }
}