#include<cstdio>
#include<algorithm>

using namespace std;
const int oo = 1000000000;

int a[3000][3000], maxp[10], minp[10], maxm[10], minm[10], p[200000];

int main() {
    for (int i = 0; i < 10; i++) maxp[i] = -oo, maxm[i] = -oo, minp[i] = +oo, minm[i] = +oo;
    int n, m, k, s;
    scanf("%d %d %d %d", &n, &m, &k, &s);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
        maxp[a[i][j]] = max(maxp[a[i][j]], i + j);
        minp[a[i][j]] = min(minp[a[i][j]], i + j);
        maxm[a[i][j]] = max(maxm[a[i][j]], i - j);
        minm[a[i][j]] = min(minm[a[i][j]], i - j);
    }
    int ans = 0;
    for (int i = 1; i <= s; i++) {
        scanf("%d", &p[i]);
        if (i == 1) continue;
        int x = p[i - 1], y = p[i];
        ans = max(ans, maxp[x] - minp[y]);
        ans = max(ans, maxp[y] - minp[x]);
        ans = max(ans, maxm[x] - minm[y]);
        ans = max(ans, maxm[y] - minm[x]);
    }
    printf("%d\n", ans);
    return 0;
}