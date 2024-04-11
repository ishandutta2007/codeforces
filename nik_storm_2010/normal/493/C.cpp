#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 2e5 + 10;

int a[N], b[N], ax, bx, n, m;

void check(int x) {
    int ay = 2 * n, by = 2 * m, l, r;
    l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (a[mid] < x) l = mid; else r = mid;
    }
    ay += n + 1 - r;
    l = 0, r = m + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (b[mid] < x) l = mid; else r = mid;
    }
    by += m + 1 - r;
    if ((ay - by > ax - bx) || (ay - by == ax - bx && ay > ax)) ax = ay, bx = by;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    ax = -1e9, bx = 1e9;
    check(0);
    for (int i = 1; i <= n; i++) check(a[i]);
    for (int i = 1; i <= m; i++) check(b[i]);
    check(1e9);
    printf("%d:%d\n", ax, bx);
    return 0;
}