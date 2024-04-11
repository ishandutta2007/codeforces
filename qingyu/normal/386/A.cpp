#include <bits/stdc++.h>

constexpr int maxn = 1005;

int a[maxn], b[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) b[i] = a[i];
    std::sort(b, b + n, [](int a, int b){return a > b;});
    for (int i = 0; i < n; ++i) if(a[i] == b[0]) {printf("%d ", ++i); break;}
    printf("%d", b[1]);
    return 0;
}