#include <cstdio>

const int N = 555555;

long long f[N], ans[N];
int a[N], r[N], ql[N], qr[N], he[N], ne[N];
int n, m;

void add(int x, long long y) {
    for (int i = x; i <= n; i |= i + 1) f[i] += y;
}

int get(int x) {
    long long ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) ret += f[i];
    return ret;
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) r[a[i]] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", ql + i, qr + i);
        --ql[i];
        --qr[i];
    }
    for (int i = 0; i < n; i++) he[i] = -1;
    for (int i = 0; i < m; i++) {
        ne[i] = he[ql[i]];
        he[ql[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j != 0) continue;
            if (r[j] < i) add(i, 1);
            if (j * j != a[i] && r[a[i] / j] < i) add(i, 1);
        }
        for (int j = a[i] + a[i]; j <= n; j += a[i]) {
            if (r[j] < i) add(i, 1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int e = he[i]; e >= 0; e = ne[e]) {
            ans[e] = get(qr[e]);
        }
        add(i, -get(i));
        for (int j = 1; j * j <= a[i]; j++) {        
            if (a[i] % j != 0) continue;
            if (r[j] > i) add(r[j], -1);
            if (j * j != a[i] && r[a[i] / j] > i) add(r[a[i] / j], -1);
        }
        for (int j = a[i] + a[i]; j <= n; j += a[i]) if (r[j] > i) add(r[j], -1);
    }
    for (int i = 0; i < m; i++) {
        printf("%I64d\n", ans[i] + qr[i] - ql[i] + 1);
    }
}