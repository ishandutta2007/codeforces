#include <bits/stdc++.h>

using namespace std;

int const N = 1234567;

int a[N], b[N], c[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) {
        b[i] = 2000000001;
        c[i] = 0;
        if (i > 0) b[i] = min(b[i], a[i] - a[i - 1]);
        if (i + 1 < n) b[i] = min(b[i], a[i + 1] - a[i]);
        c[i] = max(c[i], a[n - 1] - a[i]);
        c[i] = max(c[i], a[i] - a[0]);
        printf("%d %d\n", b[i], c[i]);
    }
}