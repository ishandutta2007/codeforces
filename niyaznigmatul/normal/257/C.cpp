#include <cstdio>
#include <cmath>
#include <algorithm>


const double PI = M_PI;
const double EPS = 1e-8;

double ang[123456];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        ang[i] = atan2(y, x);
        if (ang[i] < -EPS) ang[i] += 2 * PI;
    }
    std::sort(ang, ang + n);
    double ans = ang[n - 1] - ang[0];
    for (int i = 0; i + 1 < n; i++) {
        double cur = 2 * PI - (ang[i + 1] - ang[i]);
        if (cur < ans) ans = cur;
    }
    printf("%.17lf\n", ans / PI * 180);
}