#include <bits/stdc++.h>
using namespace std;

int N;
long long x, y;
long long a[100005], b[100005];
double closest = 100000000000000000ll, furthest = 0;

int main() {
    cin >> N >> x >> y;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        furthest = max(furthest, (double) (a[i] - x) * (a[i] - x) + (b[i] - y) * (b[i] - y));
        closest = min(closest, (double) (a[i] - x) * (a[i] - x) + (b[i] - y) * (b[i] - y));
    }

    for (int i = 0; i < N; i++) {
        long long x1 = a[i], y1 = b[i], x2 = a[(i + 1) % N], y2 = b[(i + 1) % N];
        if (x1 == x2) {
            if (y >= min(y1, y2) && y <= max(y1, y2)) {
                closest = min(closest, (double)(x - x1) * (x - x1));
            }
            continue;
        } else if (y1 == y2) {
            if (x >= min(x1, x2) && x <= max(x1, x2)) {
                closest = min(closest, (double)(y - y1) * (y - y1));
            }
            continue;
        }
        double grad1 = -(double)(x2 - x1) / (y2 - y1);
        double con1 = (double)y - grad1 * x;
        double grad2 = -1.0 / grad1;
        double con2 = (double)y1 - grad2 * x1;
        double tx = (con2 - con1) / (grad1 - grad2);
        double ty = grad2 * tx + con2;
        //printf("%Lf %Lf %Lf %Lf %Lf %Lf\n", grad1, con1, grad2, con2, tx, ty);
        if (tx >= min(x1, x2) && tx <= max(x1, x2)) {
            //printf("tx: %Lf, ty: %Lf\n", tx, ty);
            closest = min(closest, (tx - x) * (tx - x) + (ty - y) * (ty - y));
        }
    }
   // printf("%Lf %Lf\n", closest, furthest);

    double ans = 3.141592653589793238;
    ans *= (furthest - closest);
    printf("%.9lf\n", ans);
}