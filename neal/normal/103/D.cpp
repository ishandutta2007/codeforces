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

const int MAXN = 300005, MAXP = 300005, CUTOFF = 400;

struct query
{
    int a, b, original;

    inline bool operator < (const query &o) const
    {
        return b < o.b;
    }
};

int N, P, cow [MAXN];
long long bsum [MAXN], answer [MAXP];
query raid [MAXP];

int main ()
{
    scanf ("%d", &N);

    for (int i = 0; i < N; i++)
        scanf ("%d", cow + i);

    scanf ("%d", &P);

    for (int i = 0; i < P; i++)
    {
        scanf ("%d %d", &raid [i].a, &raid [i].b);
        raid [i].a--;
        raid [i].original = i;
    }

    sort (raid, raid + P);
    int i, j;

    for (i = 0, j = 0; i < P && raid [i].b < CUTOFF; i = j)
    {
        while (j < P && raid [i].b == raid [j].b)
            j++;

        for (int k = N - 1; k >= 0; k--)
            bsum [k] = cow [k] + (k + raid [i].b < N ? bsum [k + raid [i].b] : 0);

        for (int k = i; k < j; k++)
            answer [raid [k].original] = bsum [raid [k].a];
    }

    while (i < P)
    {
        long long sum = 0;

        for (int k = raid [i].a; k < N; k += raid [i].b)
            sum += cow [k];

        answer [raid [i].original] = sum;
        i++;
    }

    for (i = 0; i < P; i++)
        int_out (answer [i]);

    return 0;
}