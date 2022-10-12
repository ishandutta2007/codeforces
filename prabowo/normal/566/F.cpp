#include<bits/stdc++.h>
#define MAXN 1000002

int n;
int a[MAXN];
int b[MAXN];
int dp[MAXN];

int f(int x) {
    if (dp[x] != -1) return dp[x];
    int ret = 1;
    for (int i=2*a[x]; i<=a[n-1]; i+=a[x]) if (b[i]) ret = std::max(ret, 1 + f(b[i]));
    return dp[x] = ret;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }

    memset(dp, -1, sizeof dp);

    int ans = 0;
    for (int i=0; i<n; i++) ans = std::max(ans, f(i));
    printf("%d\n", ans);

    return 0;
}