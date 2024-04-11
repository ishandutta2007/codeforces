#include <cstdio>

using namespace std;

#define Z 1000

int n, m;
int a[202020];
int b[101010];
int c[101010];

void laske(int k) {
    int x = k*Z;
    int y = (k+1)*Z-1;
    for (int i = y; i >= x; i--) {
        if (a[i] == 0) continue;
        if (i+a[i] > y || a[i+a[i]] == 0) {
            b[i] = i;
            c[i] = 0;
        } else {
            b[i] = b[i+a[i]];
            c[i] = c[i+a[i]]+1;
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for (int i = 0; i < n/Z+1; i++) laske(i);
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d",&t);
        if (t == 0) {
            int x, y;
            scanf("%d%d",&x,&y);
            a[x] = y;
            laske(x/Z);
        } else {
            int x;
            scanf("%d",&x);
            int u = c[x];
            x = b[x];
            while (a[x+a[x]]) {
                u += 1+c[x+a[x]];
                x = b[x+a[x]];
            }
            printf("%d %d\n", x, u+1);
        }
    }
}