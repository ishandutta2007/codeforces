#include <cstdio>

const int N = 777777;
int was[N], de[N], pv[N], he[N], ne[N], ss[N], ff[N], n, m, k;

void dfs(int v) {
    was[v] = 1;
    for (int e = he[v]; e >= 0; e = ne[e]) {
        if (was[ff[e]]) {
            continue;
        }
        de[ff[e]] = de[v] + 1;
        pv[ff[e]] = v;
        dfs(ff[e]);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", ss + i, ff + i);
        --ss[i];
        --ff[i];
        ss[i + m] = ff[i];
        ff[i + m] = ss[i];
    }
    for (int i = 0; i < n; i++) he[i] = -1, was[i] = 0;
    for (int i = 0; i < m + m; i++) {
        ne[i] = he[ss[i]];
        he[ss[i]] = i;   
    }
    for (int i = 0; i < n; i++) {
        if (was[i]) continue;
        de[i] = 0;
        pv[i] = -1;
        dfs(i);
    }
    for (int i = 0; i < m + m; i++) {   
        if (de[ss[i]] - de[ff[i]] >= k) {
            printf("%d\n", de[ss[i]] - de[ff[i]] + 1);
            for (int v = ss[i]; v != ff[i]; v = pv[v]) {
                printf("%d ", v + 1);
            }
            printf("%d\n", ff[i] + 1);
            return 0;
        }
    }
}