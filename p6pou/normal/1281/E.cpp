#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 400000 + 5;

int n, N;
int ey[MAX_N], ez[MAX_N], enext[MAX_N], elast[MAX_N];
int sz[MAX_N];
long long ans1, ans2;

void dfs(int u, int fa, int dfa) {
    sz[u] = 1;
    for (int j = elast[u]; j; j = enext[j]) {
        int v = ey[j];
        if (v != fa) {
            dfs(v, u, ez[j]);
            sz[u] += sz[v];
        }
    }
    if (sz[u] & 1) {
        ans1 += dfa;
    }
    ans2 += 1ll * dfa * min(sz[u], N - sz[u]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        N = n + n;
        for (int i = 1, j = 1; i < N; i ++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            ey[j] = y;
            ez[j] = z;
            enext[j] = elast[x];
            elast[x] = j ++;
            ey[j] = x;
            ez[j] = z;
            enext[j] = elast[y];
            elast[y] = j ++;
        }
        ans1 = 0;
        ans2 = 0;
        dfs(1, 0, 0);
        printf("%lld %lld\n", ans1, ans2);
        for (int i = 1; i <= N; i ++) {
            elast[i] = 0;
        }
    }
    return 0;
}