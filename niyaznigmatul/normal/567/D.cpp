#include <bits/stdc++.h>

int const N = 1234567;

int p[N], s[N], b[N], sz[N], has[N];

int get(int x) {
    return x == p[x] ? x : (p[x] = get(p[x]));
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
        sz[x] += sz[y];
        p[y] = x;
    }
}

int main() {
    int n, k, a;
    scanf("%d%d%d", &n, &k, &a);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", b + i);
    for (int i = 0; i < m; i++) {
        --b[i];
        s[b[i]] = true;
    }
    for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
    for (int i = 0; i < n; i++) {
        if (!s[i]) {
            if (i > 0 && !s[i - 1]) unite(i - 1, i);
            if (i + 1 < n && !s[i + 1]) unite(i + 1, i);
        }
    }
    int all = 0;
    for (int i = 0; i < n; i++) if (!s[i] && i == get(i)) {
        all += (sz[i] + 1) / (a + 1);
    }
    has[m] = all;
    for (int it = m - 1; it >= 0; it--) {
        int i = b[it];
        if (!s[i]) continue;
        if (i > 0 && !s[i - 1]) {
            int v = get(i - 1);
            all -= (sz[v] + 1) / (a + 1);
        }
        if (i + 1 < n && !s[i + 1]) {
            int v = get(i + 1);
            all -= (sz[v] + 1) / (a + 1);
        }
        if (i > 0 && !s[i - 1]) unite(i - 1, i);
        if (i + 1 < n && !s[i + 1]) unite(i + 1, i);
        s[i] = false;
        all += (sz[get(i)] + 1) / (a + 1);
        has[it] = all;
    }
    for (int i = 1; i <= m; i++) {
        if (has[i] < k) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
}