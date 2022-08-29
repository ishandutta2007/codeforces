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

inline void int_out (long long x, char end = '\n')
{
#ifdef LOCAL
    printf ("%lld%c", x, end);
#else
    printf ("%I64d%c", x, end);
#endif
}

const int MAXN = 105;

int N, A [MAXN];

int main ()
{
    scanf ("%d", &N);

    for (int i = 0; i < N; i++)
        scanf ("%d", A + i);

    long long clicks = 0;

    for (int i = 0; i < N; i++)
        clicks += (long long) A [i] * (i + 1) - i;

    int_out (clicks);
    return 0;
}