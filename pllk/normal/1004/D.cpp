#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int t;
int c[1222333];
int a;
int u[1222333];
int sx, sy;
int zz;

int simu(int n, int m, int k) {
    memset(u,0,sizeof(int)*(a+1));
    int f = a;
    int df = -1;
    for (int i = 1; i <= n; i++) {
        int g = f;
        for (int j = 1; j <= m; j++) {
            u[g]++;
            if (u[g] > c[g]) return 1;
            if (g == 0) {sx = i; sy = j; df = 1;}
            if (j <= k) g--;
            else g++;
        }
        f += df;
    }
    return 0;
}

void check(int n, int m) {
    //if (a > n+m) return;
    //if (a < n/2+m/2) return;
    bool ok = false;
    for (int i = 0; i <= m; i++) {
        if (i != zz && i != m-zz+1) continue;
        if (simu(n,m,i-1) == 0) {
            printf("%d %d\n",n,m);
            printf("%d %d\n",sx,sy);
            exit(0);
        }
    }
}

int main() {
    scanf("%d",&t);
    for (int i = 1; i <= t; i++) {
        int x;
        scanf("%d",&x);
        c[x]++;
        if (x > a) a = x;
    }
    if (c[0] != 1) {
        printf("-1\n");
        return 0;
    }
    for (int z = 1; ; z++) {
        if (c[z] != 4*z) {zz = z; break;}
    }
    for (int i = t; i >= 1; i--) {
        if (t%i == 0) check(i,t/i);
    }
    printf("-1\n");
}