#include <bits/stdc++.h>
using namespace std;

int x1, y11, x2, y2, vmax, t, sx, sy, ex, ey, dx, dy;

bool attempt(double ti) {
    double adx = (double)dx, ady = (double)dy;
    if (ti <= t) {
        adx += sx * ti;
        ady += sy * ti;
    } else {
        adx += sx * t;
        ady += sy * t;
        adx += ex * (ti - t);
        ady += ey * (ti - t);
    }
    //printf("time: %lf, adjusted: (%lf, %lf)\n", ti, adx, ady);
    return adx * adx + ady * ady <= (ti * vmax) * (ti * vmax);
}

int main() {
    scanf("%d%d%d%d%d%d%d%d%d%d", &x1, &y11, &x2, &y2, &vmax, &t, &sx, &sy, &ex, &ey);
    sx *= -1;
    sy *= -1;
    ex *= -1;
    ey *= -1;
    dx = x2 - x1, dy = y2 - y11;
    double bot = 0.0, top = 1000000000.0;
    while (bot + 1e-08 < top) {
        double mid = (bot + top) / 2;
        if (attempt(mid)) top = mid;
        else bot = mid;
    }
    printf("%.8lf\n", bot);
}