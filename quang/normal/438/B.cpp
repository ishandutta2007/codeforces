#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 100010

using namespace std;

struct edge {
    int u, v, w;
    edge(int _u = 0, int _v = 0, int _w = 0) {
        u = _u;
        v = _v;
        w = _w;
    }
} b[N];

int n, m;
long long res = 0;
int a[N], f[N], s[N];

bool cmp(edge x, edge y)
{
    return x.w > y.w;
}

int Getroot(int x)
{
    return (f[x] == x)? x : (f[x] = Getroot(f[x]));
}

int main()
{
   // fi, fo;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        f[i] = i;
        s[i] = 1;
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &b[i].u, &b[i].v);
        b[i].w = min(a[b[i].u], a[b[i].v]);
    }
    sort(b + 1, b + m + 1, cmp);
    for(int i = 1; i <= m; i++) {
        int r1 = Getroot(b[i].u);
        int r2 = Getroot(b[i].v);
        if(r1 != r2) {
            f[r1] = r2;
            res += 1ll * s[r1] * s[r2] * b[i].w;
            s[r2] += s[r1];
        }
    }
    res *= 2;
    long long chia = 1ll * n * (n - 1);
    printf("%0.4f", 1.0 * res / chia);
    return 0;
}