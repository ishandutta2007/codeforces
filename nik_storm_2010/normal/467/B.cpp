#include <cstdio>

using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int a[m + 2];
    for (int i = 1; i <= m + 1; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 1; i <= m; i++) if (__builtin_popcount(a[i] ^ a[m + 1]) <= k) ans++;
    printf("%d\n", ans);
    return 0;
}