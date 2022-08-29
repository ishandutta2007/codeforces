#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

inline long long int_in ()
{
    long long x;

#ifdef LOCAL
    scanf ("%lld", &x);
#else
    scanf ("%I64d", &x);
#endif

    return x;
}

inline void int_out (long long x, char end = '\n')
{
#ifdef LOCAL
    printf ("%lld%c", x, end);
#else
    printf ("%I64d%c", x, end);
#endif
}

// End of prewritten code.

const int MAX = 10;

int N, K, A, level [MAX], loyal [MAX];
double best = 0;

double probability ()
{
    double total = 0;

    for (int mask = 0; mask < 1 << N; mask++)
    {
        double p = 1;
        int bad = 0;

        for (int i = 0; i < N; i++)
            if (mask & 1 << i)
                p *= loyal [i] / 100.0;
            else
            {
                p *= 1 - loyal [i] / 100.0;
                bad += level [i];
            }

        if (2 * __builtin_popcount (mask) > N)
            total += p;
        else
            total += p * A / (A + bad);
    }

    return total;
}

void go (int num, int k)
{
    if (num == N)
    {
        best = max (best, probability ());
        return;
    }

    go (num + 1, k);

    if (k > 0 && loyal [num] < 100)
    {
        loyal [num] += 10;
        go (num, k - 1);
        loyal [num] -= 10;
    }
}

int main ()
{
    scanf ("%d %d %d", &N, &K, &A);

    for (int i = 0; i < N; i++)
        scanf ("%d %d", level + i, loyal + i);

    go (0, K);
    printf ("%.12lf\n", best);
    return 0;
}