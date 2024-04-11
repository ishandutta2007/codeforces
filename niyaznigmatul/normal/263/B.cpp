#include <cstdio>
#include <algorithm>

int a[111];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k > n) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    std::sort(a, a + n);
    printf("%d %d", a[n - k], a[n - k]);
}