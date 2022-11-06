#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int MAX_N = 100000 + 5;
const i64 INF64 = 1e18;

int T, N;
int ey[MAX_N << 1], enext[MAX_N << 1], elast[MAX_N];
i64 al[MAX_N], ar[MAX_N];
i64 fl[MAX_N], fr[MAX_N];

void dp(int u, int fa) {
    fl[u] = fr[u] = 0;
    for (int j = elast[u]; j; j = enext[j]) {
        int v = ey[j];
        if (v != fa) {
            dp(v, u);
            fl[u] += max(fl[v] + abs(al[u] - al[v]), fr[v] + abs(al[u] - ar[v]));
            fr[u] += max(fl[v] + abs(ar[u] - al[v]), fr[v] + abs(ar[u] - ar[v]));
        }
    }
}
int main() {
    scanf("%d", &T);
    for (; T --; ) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%lld%lld", &al[i], &ar[i]);
        }
        for (int i = 1, j = 1; i < N; i ++) {
            int x, y;
            scanf("%d%d", &x, &y);
            ey[j] = y, enext[j] = elast[x], elast[x] = j ++;
            ey[j] = x, enext[j] = elast[y], elast[y] = j ++;
        }
        dp(1, 0);
        printf("%lld\n", max(fl[1], fr[1]));
        for (int i = 1; i <= N; i ++) {
            elast[i] = 0;
        }
    }
    return 0;
}