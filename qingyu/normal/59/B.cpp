#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

int n, t;
int a[50000], ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        if(x & 1) a[t++] = x;
        ans += x;
    }
    if(t == 0) return printf("0"), 0;
    if((~t) & 1) {
        std::sort(a, a + t);
        ans -= a[0];
    }
    printf("%d", ans);
    return 0;
}