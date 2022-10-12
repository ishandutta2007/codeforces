#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-7

int n;
double a[4004];
double dp[4004][2004];
bool uda[4004][2004];

double f(int x, int y) {
    if (y < 0 || 2 * n - x < y) return 2000000000;
    if (x == 2 * n) return 0;
    if (uda[x][y]) return dp[x][y];

    uda[x][y] = 1;
    double ret1 = a[x] - floor(a[x] + EPS) + f(x+1, y-1);
    double ret2 = a[x] - ceil(a[x] - EPS) + f(x+1, y);

    if (fabs(ret1) < fabs(ret2)) return dp[x][y] = ret1;
    return dp[x][y] = ret2;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<2*n; i++) scanf("%lf", &a[i]);

    printf("%.3lf\n", fabs(f(0, n)));

    return 0;
}