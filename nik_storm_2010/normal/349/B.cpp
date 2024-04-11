#include<cstdio>
#include<algorithm>

using namespace std;

int c[10];

int main() {
    int v;
    scanf("%d", &v);
    int o = 1e9;
    for (int i = 1; i <= 9; i++) {
        scanf("%d", &c[i]);
        o = min(o, c[i]);
    }
    int lim = v / o;
    if (lim == 0) printf("%d", -1);
    else {
        for (int l = 1; l <= lim; l++) {
            int x = 0;
            for (int i = 1; i <= 9; i++) if (c[i] + (lim - l) * o <= v) x = i;
            v -= c[x];
            printf("%d", x);
        }
    }
    return 0;
}