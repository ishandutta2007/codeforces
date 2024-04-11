#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3500 + 5;

int T, N, M, K;
int a[MAX_N], A;

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d%d", &N, &M, &K);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
        }
        K = min(K, M - 1);
        A = 0;
        for (int kl = 0; kl <= K; kl ++) {
            int kr = K - kl;
            int res = 2e9;
            for (int i = 0; i <= M - 1 - K; i ++) {
                res = min(res, max(a[1 + kl + i], a[N - (kr + M - 1 - K - i)]));
            }
            A = A < res ? res : A;
        }
        printf("%d\n", A);
    }
    return 0;
}