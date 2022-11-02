#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1e3;

int a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int ans = 0, i = 1, j = 1;
    while (i <= n && j <= m) {
        if (abs(a[i] - b[j]) <= 1) ans++, i++, j++; else
        if (a[i] > b[j]) j++; else i++;
    }
    printf("%d\n", ans);
    return 0;
}