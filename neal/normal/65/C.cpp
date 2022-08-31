#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 10005, ITER = 200;
const double EPS = 1e-12;

inline double dist (double dx, double dy, double dz)
{
    return sqrt (dx * dx + dy * dy + dz * dz);
}

inline double trans (double a, double b, double frac)
{
    return a + (b - a) * frac;
}

int N, x [MAXN], y [MAXN], z [MAXN];
int X, Y, Z, VP, VS;

int main ()
{
    scanf ("%d", &N);

    for (int i = 0; i <= N; i++)
        scanf ("%d %d %d", x + i, y + i, z + i);

    scanf ("%d %d %d %d %d", &VP, &VS, &X, &Y, &Z);
    double elapsed = 0;

    for (int i = 0; i < N; i++)
    {
        double harry = dist (X - x [i + 1], Y - y [i + 1], Z - z [i + 1]) / VP;
        double segment = dist (x [i + 1] - x [i], y [i + 1] - y [i], z [i + 1] - z [i]) / VS;
        double snitch = elapsed + segment;

        if (harry <= snitch * (1 + EPS))
        {
            double lo = 0, hi = 1, nharry, nsnitch;

            for (int it = 0; it < ITER; it++)
            {
                double mid = (lo + hi) / 2;
                nharry = dist (X - trans (x [i], x [i + 1], mid), Y - trans (y [i], y [i + 1], mid), Z - trans (z [i], z [i + 1], mid)) / VP;
                nsnitch = elapsed + segment * mid;

                if (nharry <= nsnitch)
                    hi = mid;
                else
                    lo = mid;
            }

            puts ("YES");
            printf ("%.9lf\n%.9lf %.9lf %.9lf\n", nharry, trans (x [i], x [i + 1], lo), trans (y [i], y [i + 1], lo), trans (z [i], z [i + 1], lo));
            return 0;
        }

        elapsed += segment;
    }

    puts ("NO");
    return 0;
}