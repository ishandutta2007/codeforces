#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n;
int a[N][N];
long double p[N][N * 4], e[N][N * 4], mx[N * 4];

void go(int node, int l, int r, int val) {
    if (l == r) {
        p[l][node] = 1.;
        e[l][node] = 0.;
        mx[node] = 0.;
        return;
    }
    int m = (l + r) >> 1;
    go(node << 1, l, m, val >> 1);
    go(node << 1 | 1, m + 1, r, val >> 1);
    for (int i = l; i <= m; i++) {
        for (int j = m + 1; j <= r; j++) {
            long double foo = p[i][node << 1] * p[j][node << 1 | 1];
            p[i][node] += foo * (long double)a[i][j] / 100.;
            p[j][node] += foo * (long double)a[j][i] / 100.;
        }
    }
    for (int i = l; i <= m; i++) {
        e[i][node] = p[i][node] * (long double)val + e[i][node << 1] + mx[node << 1 | 1];
        mx[node] = max(mx[node], e[i][node]);
    }
    for (int i = m + 1; i <= r; i++) {
        e[i][node] = p[i][node] * (long double)val + e[i][node << 1 | 1] + mx[node << 1];
        mx[node] = max(mx[node], e[i][node]);
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n * 4; j++) {
            p[i][j] = e[i][j] = 0;
            mx[j] = 0;
        }
    }

}

int main() {
    scanf("%d", &n);
    n = (1 << n);
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", a[i] + j);
        }
    }
    go(1, 1, n, n / 2);
    printf("%0.14f", (double)mx[1]);
    return 0;
}