#include <bits/stdc++.h>

using namespace std;

typedef double f64;
const int MAX_N = 3000 + 5;
const f64 PI = 3.1415926535897932384626433832795;
const f64 EPS = 1e-7;

struct Point {
    f64 x, y;
    Point() : x(0), y(0) {}
    Point(f64 x_, f64 y_) : x(x_), y(y_) {}
    Point operator + (const Point &b) const {
        return Point(x + b.x, y + b.y);
    }
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
};
f64 dis2(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int N, pt[MAX_N], ans;
Point p[MAX_N];
f64 R, pl[MAX_N], pr[MAX_N];

int main() {
    scanf("%d%lf", &N, &R);
    for (int i = 1; i <= N; i ++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    for (int i = 1; i <= N; i ++) {
        f64 &li = pl[i] = -PI, &ri = pr[i] = PI;
        for (int j = 1; j <= N; j ++) {
            f64 d2 = dis2(p[i], p[j]);
            if (d2 <= (R + EPS) * (R + EPS)) continue;
            f64 a = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
            f64 b = asin(R / sqrt(d2));
            f64 l = a - b, r = a + b;
            if (l < -PI - EPS) l += PI * 2;
            if (r > PI + EPS) r -= PI * 2;
            // printf("    i=%d,j=%d,  li=%lf,ri=%lf,  l=%lf,r=%lf\n", i, j, li, ri, l, r);
            if (li == -PI && ri == PI) {
                li = l, ri = r;
            } else if (li < ri + EPS) {
                if (l < r + EPS) {
                    if (li < r + EPS && l < ri + EPS) {
                        li = max(li, l), ri = min(ri, r);
                    } else {
                        li = ri = 10;
                        break;
                    }
                } else {
                    if (l < ri + EPS) {
                        li = max(li, l);
                    } else if (li < r + EPS) {
                        ri = min(ri, r);
                    } else {
                        li = ri = 10;
                        break;
                    }
                }
            } else {
                if (l < r + EPS) {
                    if (l < ri + EPS) {
                        li = l, ri = min(ri, r);
                    } else if (li < r + EPS) {
                        ri = r, li = max(li, l);
                    } else {
                        li = ri = 10;
                        break;
                    }
                } else {
                    li = max(li, l), ri = min(ri, r);
                }
            }
        }
        // printf("i=%d, pl=%lf,pr=%lf\n", i, pl[i], pr[i]);
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = i + 1; j <= N; j ++) {
            f64 a = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
            int ok = 1;
            if (pl[i] < pr[i] + EPS) {
                if (pl[i] - EPS <= a && a <= pr[i] + EPS);
                else if (abs(pl[i] + PI) < EPS && abs(a - PI) < EPS);
                else if (abs(pr[i] - PI) < EPS && abs(a + PI) < EPS);
                else ok = 0;
            } else {
                if (a <= pr[i] + EPS || pl[i] - EPS <= a);
                else ok = 0;
            }
            a = a <= 0 ? a + PI : a - PI;
            if (pl[j] < pr[j] + EPS) {
                if (pl[j] - EPS <= a && a <= pr[j] + EPS);
                else if (abs(pl[j] + PI) < EPS && abs(a - PI) < EPS);
                else if (abs(pr[j] - PI) < EPS && abs(a + PI) < EPS);
                else ok = 0;
            } else {
                if (a <= pr[j] + EPS || pl[j] - EPS <= a);
                else ok = 0;
            }
            // if (ok) printf("i=%d,j=%d\n", i, j);
            ans += ok;
        }
    }
    printf("%d\n", ans);
    return 0;
}