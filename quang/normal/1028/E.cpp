#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];
long long b[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    a[0] = a[n];
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= a[i - 1]) {
            continue;
        }
        if (mx == 0 || a[i] > a[mx]) {
            mx = i;
        }
    }
    if (!mx) {
        if (a[1]) puts("NO");
        else {
            puts("YES");
            for (int i = 1; i <= n; i++) {
                printf("1 ");
            }
            printf("\n");
        }
        return 0;
    }
    b[mx] = 2ll * a[mx];
    for (int i = mx - 1; i >= 1; i--) {
         b[i] = b[i + 1] + a[i];
    }
    b[n + 1] = b[1];
    for (int i = n; i > mx; i--) {
        b[i] = b[i + 1] + a[i];
    }
    b[mx] = a[mx];
    puts("YES");
    for (int i = 1; i <= n; i++) {
        printf("%lld ", b[i]);
    }
    printf("\n");
    return 0;
}