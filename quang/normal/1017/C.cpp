#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

int main() {
    scanf("%d", &n);
    int x = sqrt(n);
    for (int i = 1; i <= n; i++) {
        a[i] = n - i + 1;
    }
    for (int i = 1; i <= n; i += x) {
        reverse(a + i, a + min(i + x, n + 1));
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}