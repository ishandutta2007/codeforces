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

const int MAXN = 100005, MOD = 1000000009;

int N, M, parent [MAXN];

int find (int x)
{
    return x == parent [x] ? x : parent [x] = find (parent [x]);
}

int main ()
{
    scanf ("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        parent [i] = i;

    int ways = 1;

    for (int x, y, i = 0; i < M; i++)
    {
        scanf ("%d %d", &x, &y); x--; y--;
        x = find (x);
        y = find (y);

        if (x == y)
            ways = 2 * ways % MOD;
        else
            parent [x] = y;

        printf ("%d\n", (ways + MOD - 1) % MOD);
    }

    return 0;
}