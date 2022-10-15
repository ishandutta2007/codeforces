#include <bits/stdc++.h>

using namespace std;

int const N = 111;
int a[N][N], ans[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", a[i] + j);
    }
    int ac = 0;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1 || a[i][j] == 3) {
                ok = false;
            }
            if (a[j][i] == 2 || a[j][i] == 4) {
                ok = false;
            } 
        }
        if (ok) ans[ac++] = i;
    }
    printf("%d\n", ac);
    for (int i = 0; i < ac; i++) {
        if (i > 0) putchar(' ');
        printf("%d", ans[i] + 1);
    }
    puts("");
}