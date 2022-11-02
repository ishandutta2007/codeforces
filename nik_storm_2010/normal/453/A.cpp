#include <cstdio>

using namespace std;

double power(double x, int step)
{
    if (step == 0) return 1.0;
    double res = power(x, step >> 1);
    res *= res;
    if (step % 2) res *= x;
    return res;
}

int main()
{
    int n, m;
    scanf("%d %d", &m, &n);
    double ans = m;
    for (int i = 1; i < m; i++) ans -= power((i + 0.0) / m, n);
    printf("%.6lf\n", ans);
    return 0;
}