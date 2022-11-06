#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int MAX_N = 100000 + 5;
const i64 INF64 = 1.1e18;

int T, N;
i64 K, f[MAX_N];

int main() {
    N = 1e5;
    f[0] = f[1] = 1;
    for (int i = 2; i <= N; i ++) {
        f[i] = min(INF64, f[i - 1] << 1);
    }

    scanf("%d", &T);
    for (; T --; ) {
        scanf("%d%lld", &N, &K);
        if (K > f[N]) {
            printf("-1\n");
        } else {
            for (int i = 1, t; i <= N; i += t) {
                for (t = 1; t <= N - i + 1; t ++) {
                    if (K <= f[N - i + 1 - t]) {
                        for (int j = 1; j <= t; j ++) {
                            printf("%d ", i + t - j);
                        }
                        break;
                    } else {
                        K -= f[N - i + 1 - t];
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}