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

bool bullet (long long N, long long K, long long X)
{
    if (N % 2 == 1)
    {
        if (X == N || K <= 1)
            return X == N && K >= 1;

        N--;
        K--;
    }

    if (K <= N / 2)
        return X % 2 == 0 && X >= N - 2 * (K - 1);
    else
        return X % 2 == 0 || X >= N - 2 * (K - N / 2) + 1;
}

int main ()
{
    long long N, K, X;
    int P;
    N = int_in ();
    K = int_in ();
    P = int_in ();

    for (int i = 0; i < P; i++)
    {
        X = int_in ();
        putchar (bullet (N, K, X) ? 'X' : '.');
    }

    putchar ('\n');
    return 0;
}