#include <cstdio>

using namespace std;
const int N = 100;

int a[N], b[N], c[N], d[N];

int main() {
    int p, q, l, r;
    scanf("%d %d %d %d", &p, &q, &l, &r);
    for (int i = 1; i <= p; i++) scanf("%d %d", &a[i], &b[i]);
    for (int i = 1; i <= q; i++) scanf("%d %d", &c[i], &d[i]);
    int ans = 0;
    for (int getup = l; getup <= r; getup++) {
        bool good = false;
        for (int i = 1; i <= p; i++) for (int j = 1; j <= q; j++) {
            if (a[i] <= c[j] + getup && c[j] + getup <= b[i]) good = true;
            if (a[i] <= d[j] + getup && d[j] + getup <= b[i]) good = true;
            if (c[j] + getup <= a[i] && a[i] <= d[j] + getup) good = true;
            if (c[j] + getup <= b[i] && b[i] <= d[j] + getup) good = true;
        }
        ans += (good ? 1 : 0);
    }
    printf("%d\n", ans);
    return 0;
}