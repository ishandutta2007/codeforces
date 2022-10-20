#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 300010

using namespace std;

struct edge {
    int u, v, w;
    bool operator < (const edge &a) const {
        return w < a.w;
    }
} a[N];

int n, m;
int b[N], c[N];

int main() {
    //fi, fo;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
    sort(a + 1 , a + m + 1);
    int ans = 0, pre = 0;
    for(int i = 1; i <= m; i++) {
        b[i] = c[a[i].u] + 1;
        ans = max(ans, b[i]);
        if(a[i].w != a[i + 1].w) {
            for(int j = pre; j <= i; j++) c[a[j].v] = max(c[a[j].v], b[j]);
            pre = i + 1;
        }
    }
    printf("%d", ans);
    return 0;
}