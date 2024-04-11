#include <bits/stdc++.h>
using namespace std;

int N, P, l[300005], r[300005];

int main() {
    scanf("%d%d", &N, &P);
    for (int i = 0; i < N; i++) scanf("%d%d", &l[i], &r[i]);
    double ans = 0;
    for (int i = 0; i < N; i++) {
        double p1 = (r[i] / P) - (l[i] - 1) / P;
        p1 /= (r[i] - l[i] + 1);
        double p2 = (r[(i + 1) % N] / P) - (l[(i + 1) % N] - 1) / P;
        p2 /= (r[(i + 1) % N] - l[(i + 1) % N] + 1);


        ans += 1000.0 * (p1 + p2 - p1 * p2);
    }
    printf("%.8lf\n", ans * 2);
}