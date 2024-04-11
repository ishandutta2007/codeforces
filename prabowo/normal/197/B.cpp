#include <cstdio>
#include <cstdlib>

int n, m;
int p, q;

int gcd(int x, int y) {
    return (y == 0) ? x : gcd(y, x % y);
}

int main () {
    scanf("%d %d", &n, &m);
    int tmp;

    scanf("%d", &p);
    for (int i=0; i<n; i++) scanf("%d", &tmp);
    scanf("%d", &q);
    for (int i=0; i<m; i++) scanf("%d", &tmp);

    if (n > m) {
        if (p / abs(p) * q / abs(q) > 0) puts("Infinity");
        else puts("-Infinity");
    } else if (n < m) puts("0/1");
    else {
        int fpb = gcd(p, q);
        p /= fpb, q /= fpb;

        int sign = p / abs(p) * q / abs(q);
        p = abs(p), q = abs(q);

        if (sign < 0) printf("-");

        printf("%d/%d\n", p, q);
    }
    return 0;
}