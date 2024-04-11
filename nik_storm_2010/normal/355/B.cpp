#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 1000 + 10;

int a[N], b[N];

int main() {
    int c1, c2, c3, c4, n, m;
    scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    int ans = c4;
    int k1, k2;
    k1 = k2 = 0;
    for (int i = 0; i < n; i++) k1 += min(a[i] * c1, c2);
    for (int i = 0; i < m; i++) k2 += min(b[i] * c1, c2);
    ans = min(ans, min(k1, c3) + min(k2, c3));
    printf("%d", ans);
    return 0;
}