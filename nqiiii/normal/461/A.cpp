#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const int maxN = 300000;
int n, a[maxN + 10];
Long ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    ans += 1ll * a[n] * n;
    for (int i = 1; i < n; ++i)
        ans += 1ll * a[i] * (i + 1);
    printf("%lld", ans);
}