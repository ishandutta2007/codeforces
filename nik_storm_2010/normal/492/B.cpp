#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 2e3;

int a[N];

int main() {
    int n, l;
    scanf("%d %d", &n, &l);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    double x = max(a[1], l - a[n]);
    for (int i = 1; i < n; i++) x = max(x, (a[i + 1] - a[i]) / 2.0);
    printf("%.9lf\n", x);
    return 0;
}