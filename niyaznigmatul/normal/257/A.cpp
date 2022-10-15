#include <cstdio>
#include <algorithm>

int a[1234];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    std::sort(a, a + n);
    int cnt = 0;
    for (int i = n - 1; i >= 0 && k < m; i--) {
        k += a[i] - 1;
        ++cnt;
    }
    if (k < m) puts("-1"); else printf("%d\n", cnt);
}