#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

int ask(vector<long long> &a) {
    printf("%d ", (int)a.size());
    for (long long u : a) {
        printf("%lld ", u);
    }
    printf("\n");
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

long long dp[10][N + 10];

long long get(int id, long long u, int num) {
    if (num == 0) {
        return u;
    }
    if (u >= N) {
        long long x = dp[id - 1][N] - N;
        return u + x * num;
    } else {
        return get(id, dp[id - 1][u], num - 1);
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        dp[1][i] = i + (i + 1) + 1;
        dp[0][i] = i + 1;
    }
    dp[1][N] = N + N + 1;
    dp[0][N] = N + 1;
    for (int id = 2; id <= 5; id++) {
        for (int i = 0; i <= N; i++) {
            dp[id][i] = get(id, i, min(i + 2, N + 1));
        }
    }
    long long low = 0;
    for (int id = 5; id > 0; id--) {
        vector<long long> a;
        long long cur = low;
        for (int i = 1; i <= min(1ll * N, low + 1); i++) {
            cur = (cur <= N ? dp[id - 1][cur] : cur + dp[id - 1][N] - N);
            a.push_back(cur);
        }
        int ver = ask(a);
        if (ver < 0) {
            return 0;
        }
        if (ver > 0) {
            low = a[ver - 1];
        }
    }
    return 0;
}