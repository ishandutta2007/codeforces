#include <bits/stdc++.h>
using namespace std;
const int maxN = 100000;

struct Node {
    int x, y;
    bool operator < (const Node &t) const {
        return x < t.x;
    }
}a[maxN + 10];

int n, f[maxN + 10], b[maxN + 10], ans = 1e9;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) b[i] = a[i].x;
    for (int i = 1; i <= n; ++i) {
        int pos = lower_bound(b + 1, b + n + 1, a[i].x - a[i].y) - b - 1;
        f[i] = f[pos] + i - 1 - pos; ans = min(ans, f[i] + n - i);
    }
    printf("%d", ans);
}