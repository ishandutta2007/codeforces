#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <stdio.h>
int a[1000005];
int main() {
//    freopen("input.txt", "r", stdin);
    int tst;
    scanf("%d", &tst);
    while (tst--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n * k; i++) {
            scanf("%d", &a[i]);
        }
        long long ans = 0;
        int step = (n + 2) / 2;
        int from = (n * k) - step;
        for (int c = 0; c < k; c++) {
            ans += a[from];
            from -= step;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}