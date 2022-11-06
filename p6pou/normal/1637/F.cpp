#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const int MAX_N = 200000 + 5;

int N;
int a[MAX_N], fath[MAX_N];
int ey[MAX_N << 1], enext[MAX_N << 1], elast[MAX_N];
int f1[MAX_N], f2[MAX_N];
i64 g1[MAX_N], g2[MAX_N], ans;

void dp1(int u, int fa) {
    fath[u] = fa;
    int son_cnt = 0;
    for (int j = elast[u]; j; j = enext[j]) {
        int v = ey[j];
        if (v != fa) {
            son_cnt ++;
            dp1(v, u);
            f1[u] = max(f1[u], f1[v]);
            g1[u] += g1[v];
        }
    }
    if (son_cnt == 0) {
        f1[u] = g1[u] = a[u];
    }
    if (f1[u] < a[u]) {
        g1[u] += a[u] - f1[u];
        f1[u] = a[u];
    }
}
void dp2(int u, int fa) {
    int t1 = f2[u], t2 = 0;
    i64 s = g2[u];
    for (int j = elast[u]; j; j = enext[j]) {
        int v = ey[j];
        if (v != fa) {
            s += g1[v];
            if (t1 < f1[v]) t2 = t1, t1 = f1[v];
            else if (t2 < f1[v]) t2 = f1[v];
        }
    }
    for (int j = elast[u]; j; j = enext[j]) {
        int v = ey[j];
        if (v != fa) {
            f2[v] = f1[v] != t1 ? t1 : t2;
            g2[v] = s - g1[v];
            if (f2[v] < a[u]) {
                g2[v] += a[u] - f2[v];
                f2[v] = a[u];
            }
            dp2(v, u);
        }
    }
}

int main() {
    scanf("%d", &N);
    int ma = 0;
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
        ma = max(ma, a[i]);
    }
    for (int i = 1, j = 2; i < N; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        ey[j] = y, enext[j] = elast[x], elast[x] = j ++;
        ey[j] = x, enext[j] = elast[y], elast[y] = j ++;
    }
    dp1(1, 0);
    dp2(1, 0);
    ans = 1e18;
    for (int u = 1; u <= N; u ++) {
        int f = f2[u];
        i64 g = g2[u];
        for (int j = elast[u]; j; j = enext[j]) {
            int v = ey[j];
            if (v != fath[u]) {
                f = max(f, f1[v]);
                g += g1[v];
            }
        }
        if (f < a[u]) {
            g += a[u] - f;
            f = a[u];
        }
        // printf("i=%d, f1=%d,g1=%lld,  f2=%d, g2=%lld\n", i, f1[i], g1[i], f2[i], g2[i]);
        ans = min(ans, g + ma);
    }
    printf("%lld\n", ans);
    return 0;
}