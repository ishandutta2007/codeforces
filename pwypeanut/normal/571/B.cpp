#include <bits/stdc++.h>
using namespace std;

int N, K, arr[300005];
long long dp[5005][5005];

long long f(int k, int m) {
    if (k == 0 && m == 0) return 0;
    if (k == 0) return -100000000000000000ll;
    if (m < 0) return -100000000000000000ll;
    if (dp[k][m] != -1) return dp[k][m];
    int curl = k * (N/K) + m;
    int extra = 0;
    if (curl != N) extra = arr[curl] - arr[curl - 1];
    return dp[k][m] = max(f(k-1, m-1), f(k-1, m)) + extra;
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    sort(arr, arr + N);
    int len_array = N/K;
    int more = N % K;
    memset(dp, -1, sizeof(dp));
    printf("%I64d\n", (arr[N-1] - arr[0]) - f(K, more));
}