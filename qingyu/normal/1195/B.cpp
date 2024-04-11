#include <cstdio>
#include <cmath>

int main()
{
    long double n, k;
    scanf("%Lf%Lf", &n, &k);
    long double delta = 9 + 8 * n + 8 * k;
    long double x = (sqrtl(delta) - 3) / 2;
    long double result = n - x;
    printf("%d\n", (int)result);
    return 0;
}