#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 510;
const long long INF = ((long long)1e9 + 7)*1000000000;

struct KuhnMunkres {
    long long sum, mx[N], my[N], lx[N], ly[N], sx[N], sy[N];
    bool vx[N], vy[N];
    long long gao(int n, long long e[N][N]) {
        fill_n(mx, n, -1);
        fill_n(my, n, -1);
        fill_n(ly, n, 0);
        for (int i = 0; i < n; ++i) lx[i] = *max_element(e[i], e[i]+n);
        for (int x = 0, y, z, w; x < n; ++x) {
            fill_n(vx, n, false);
            fill_n(vy, n, false);
            queue<int> q;
            vx[x] = true;
            for (int i = 0; i < n; ++i) {
                sx[i] = x, sy[i] = lx[x] + ly[i] - e[x][i];
                if (!sy[i]) q.push(i), vy[i] = true;
            }
            while (1) {
                if (q.empty()) {
                    long long delta = *min_element(sy, sy+n);
                    for (int i = 0; i < n; ++i) {
                        if (vx[i]) lx[i] -= delta;
                        if (vy[i]) ly[i] += delta;
                        else if (!(sy[i] -= delta)) q.push(i), vy[i] = true;
                    }
                } else {
                    y = q.front(); q.pop();
                    if (!~my[y]) break;
                    vx[z = my[y]] = vy[y] = true, sy[y] = INF;
                    for (int i = 0; i < n; ++i) if (!vy[i]) {
                        long long d = lx[z] + ly[i] - e[z][i];
                        if (sy[i] > d) sy[i] = d, sx[i] = z;
                        if (!sy[i]) q.push(i), vy[i] = true;
                    }
                }
            }
            for (; ~y; y = w) z = sx[y], w = mx[z], mx[z] = y, my[y] = z;
        }
        for (int i = sum = 0; i < n; ++i) sum += lx[i] + ly[i];
        return sum;
    }
} km;
#define rep(i,n) for(int i=1;i<=n;i++)
int n,a[N],b[N],k[N];
long long e[N][N];

int main()
{
    scanf("%d", &n);
    rep(i,n)scanf("%d%d%d",&a[i],&b[i],&k[i]);
    rep(i,n)rep(j,n)e[i-1][j-1]=max(0ll,a[i]-1ll*min(j-1,k[i])*b[i]);
    printf("%lld\n",km.gao(n,e));
    return 0;
}