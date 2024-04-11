#include <cstdio>

using namespace std;
const int N = 1e5 + 10;

int a[N];

int check(int n, int need) {
    int i = 1, j = 1;
    while (j <= n) {
        if (a[j] - a[i] == need) return a[i];
        if (a[j] - a[i] < need) j++; else i++;
    }
    return -1;
}

int reverse_check(int n, int need) {
    int i = n, j = n;
    while (i >= 1) {
        if (a[j] - a[i] == need) return a[i];
        if (a[j] - a[i] < need) i--; else j--;
    }
    return -1;
}

int main() {
    int n, l, x, y;
    scanf("%d %d %d %d", &n, &l, &x, &y);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int hx = check(n, x), hy = check(n, y);
    if (hx != -1 && hy != -1) printf("0\n");
    if (hx == -1 && hy != -1) printf("1\n%d\n", x);
    if (hx != -1 && hy == -1) printf("1\n%d\n", y);
    if (hx == -1 && hy == -1)  {
        int plus = check(n, x + y), minus = check(n, y - x), rminus = reverse_check(n, y - x);
        if (plus != -1) printf("1\n%d\n", plus + x); else
        if (minus != -1 && minus + y <= l) printf("1\n%d\n", minus + y); else
        if (minus != -1 && minus - x >= 1) printf("1\n%d\n", minus - x); else
        if (rminus != -1 && rminus + y <= l) printf("1\n%d\n", rminus + y); else
        if (rminus != -1 && rminus - x >= 1) printf("1\n%d\n", rminus - x); else printf("2\n%d %d\n", x, y);
    }
    return 0;
}