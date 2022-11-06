#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n > m) {
        swap(n, m);
    }
    if (n == 1) {
        printf("%d\n", m - min(m % 6, 6 - m % 6));
    } else if (n == 2) {
        if (m == 2) {
            printf("0\n");
        } else if (m == 3) {
            printf("4\n");
        } else if (m == 7) {
            printf("12\n");
        } else {
            printf("%d\n", m * 2);
        }
    } else {
        printf("%lld\n", 1ll * n * m - (1ll * n * m % 2));
    }
    return 0;
}