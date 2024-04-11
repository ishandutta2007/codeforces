#include <cstdio>
#include <cassert>

int ed[222222][6], p[222222], cn, n, was[222222], deg[222222], z[222222];

int dfs(int v) {
    was[v] = 1;
    p[cn++] = v;
    if (cn == n) {
        int ok1 = 0;
        int ok2 = 0;
        for (int i = 0; i < 4; i++) {
            if (ed[v][i] == p[0]) ok1 = 1;
            if (ed[v][i] == p[1]) ok2 = 1;
        }
        if (!ok1 || !ok2) return 0;
        ok1 = 0;
        for (int i = 0; i < 4; i++) {
            if (ed[p[cn - 2]][i] == p[0]) {
                ok1 = 1;
                break;
            }
        }
        return ok1;
    }
    for (int i = 0; i < 4; i++) {
        int go = ed[v][i];
        if (was[go]) continue;
        if (cn > 1) {
            int ok = 0;
            for (int j = 0; j < 4; j++) {
                if (ed[go][j] == p[cn - 2]) {
                    ok = 1;
                    break;
                }
            }
            if (!ok) continue;
        }
        if (dfs(go)) {
            return 1;
        }
    }
    --cn;
    was[v] = 0;
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        ed[a][deg[a]++] = b;
        ed[b][deg[b]++] = a;
        if (deg[a] > 4 || deg[b] > 4) {
            puts("-1");
            return 0;
        }
    }
    cn = 0;
    if (!dfs(0)) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        printf("%d", p[i] + 1);
    }
    for (int i = 0; i < n; i++) z[p[i]] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            int v = ed[i][j];
            int dif = z[i] - z[v];
            if (dif < 0) dif += n;
            if (dif > n - dif) dif = n - dif;
            assert(dif <= 2);
        }
    }
    puts("");
}