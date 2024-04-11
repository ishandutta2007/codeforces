#include <stdio.h>
#include <math.h>


int n, t, m, p;
double c, a[200010], pa[200010], mean;
double real[200010], approx[200010];

int main() {
    scanf("%d%d%lf", &n, &t, &c);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
        pa[i] = a[i] + (i ? pa[i - 1] : 0);
        if (i + 1 >= t)
            real[i] = (pa[i] - (i >= t ? pa[i - t] : 0)) / t;
        mean = (mean + a[i] / t) / c;
        approx[i] = mean;
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &p);
        p--;
        printf("%.8lf %.8lf %.8lf\n", real[p], approx[p], fabs(real[p] - approx[p]) / real[p]);
    }
}