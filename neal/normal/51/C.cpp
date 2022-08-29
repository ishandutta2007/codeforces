#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 200005, ITER = 70;

int N, x [MAXN];

vector <double> solution (double d)
{
    vector <double> v;
    double cover = -1e100;

    for (int i = 0; i < N && v.size () <= 3; i++)
        if (x [i] > cover)
        {
            v.push_back (x [i] + d);
            cover = x [i] + 2 * d;
        }

    while (v.size () < 3)
        v.push_back (cover);

    return v.size () <= 3 ? v : vector <double> ();
}

int main ()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> x [i];

    sort (x, x + N);
    double lo = 0, hi = 1e9;

    for (int it = 0; it < ITER; it++)
    {
        double mid = (lo + hi) / 2;

        if (solution (mid).empty ())
            lo = mid;
        else
            hi = mid;
    }

    vector <double> v = solution (hi);
    printf ("%lf\n%lf %lf %lf\n", hi, v [0], v [1], v [2]);
    return 0;
}