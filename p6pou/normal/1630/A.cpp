#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n, k;
    for (scanf("%d", &T); T --; ) {
        scanf("%d%d", &n, &k);
        if (n == 4 && k == 3) {
            printf("-1\n");
        } else if (k == 0) {
            for (int i = 0; i < n >> 1; i ++) {
                printf("%d %d\n", i, n - 1 - i);
            }
        } else if (k == n - 1) {
            printf("%d %d\n", 0, 1);
            printf("%d %d\n", 2, n - 2);
            printf("%d %d\n", n - 3, n - 1);
            for (int i = 3; i < n >> 1; i ++) {
                printf("%d %d\n", i, n - 1 - i);
            }
        } else {
            printf("%d %d\n", 0, n - 1 - k);
            printf("%d %d\n", k, n - 1);
            for (int i = 1; i < n >> 1; i ++) {
                if (i == k || i == n - 1 - k) continue;
                printf("%d %d\n", i, n - 1 - i);
            }
        }
    }
    return 0;
}