#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const int maxN = 100000;
int n, x[maxN + 10], y[maxN + 10];
int a[maxN + 10], aCnt;

bool OnLine(int p, int q, int d) {
    return 1ll * (x[p] - x[q]) * (y[p] - y[d]) == 1ll * (x[p] - x[d]) * (y[p] - y[q]); 
}

bool Check(int p, int q) {
    aCnt = 0;
    for (int i = 1; i <= n; ++i)
        if (!OnLine(p, q, i)) a[++aCnt] = i;
    if (aCnt <= 1) return 1;
    else {
        for (int i = 3; i <= aCnt; ++i)
            if (!OnLine(a[1], a[2], a[i])) return 0;
        return 1;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    if (n == 1) {
        puts("YES"); return 0;
    }
    for (int i = 1; i <= min(n, 3); ++i)
        for (int j = i + 1; j <= min(n, 3); ++j)
            if (Check(i, j)) {
                printf("YES"); return 0;
            }
    printf("NO");
}