#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 105, ITER = 100;

inline double dist (double dx, double dy)
{
    return sqrt (dx * dx + dy * dy);
}

inline double prob (double dist, double rad)
{
    return dist <= rad ? 1 : (rad == 0 ? 0 : exp (1 - dist * dist / (rad * rad)));
}

int N, K, EPS, X0, Y0, X [MAXN], Y [MAXN];
double succ, bomb [MAXN];

double success (double radius)
{
    for (int i = 0; i <= K; i++)
        bomb [i] = 0;

    bomb [0] = 1;

    for (int i = 0; i < N; i++)
    {
        double p = prob (dist (X [i], Y [i]), radius);

        for (int k = K; k >= 0; k--)
            bomb [k] = (k > 0 ? p * bomb [k - 1] : 0) + (k == K ? bomb [k] : (1 - p) * bomb [k]);
    }

    return bomb [K];
}

int main ()
{
    scanf ("%d %d %d", &N, &K, &EPS);
    scanf ("%d %d", &X0, &Y0);
    succ = 1 - EPS / 1000.0;

    for (int i = 0; i < N; i++)
    {
        scanf ("%d %d", X + i, Y + i);
        X [i] -= X0; Y [i] -= Y0;
    }

    double lo = 0, hi = 5000;

    for (int it = 0; it < ITER; it++)
    {
        double mid = (lo + hi) / 2;

        if (success (mid) >= succ)
            hi = mid;
        else
            lo = mid;
    }

    printf ("%.12lf\n", lo);
    return 0;
}