// #define NDEBUG
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

const int MAXN = 100005;

inline bool lucky (long long x)
{
    assert (x >= 0);

    while (x != 0)
    {
        if (x % 10 != 4 && x % 10 != 7)
            return false;

        x /= 10;
    }

    return true;
}

int N, array [MAXN];
pair <int, int> sorted [MAXN];
int C, cycle [MAXN];
vector <pair <int, int> > swaps;

inline void add_swap (int a, int b)
{
    swaps.push_back (make_pair (a, b));
}

int main ()
{
    scanf ("%d", &N);

    for (int i = 0; i < N; i++)
        scanf ("%d", array + i);

    int X = -1;

    for (int i = 0; i < N; i++)
        if (lucky (array [i]))
        {
            X = i;
            break;
        }

    if (X == -1)
    {
        for (int i = 0; i + 1 < N; i++)
            if (array [i] > array [i + 1])
            {
                puts ("-1");
                return 0;
            }

        puts ("0");
        return 0;
    }

    for (int i = 0; i < N; i++)
        sorted [i] = make_pair (array [i], i);

    sort (sorted, sorted + N);
    memset (cycle, -1, sizeof (cycle));
    C = 0;

    for (int i = 0; i < N; i++)
        if (cycle [i] == -1)
        {
            for (int j = i; cycle [j] == -1; j = sorted [j].second)
                cycle [j] = C;

            C++;
        }

    for (int i = 0; i < N; i++)
        if (cycle [i] != -1 && cycle [i] != cycle [X])
        {
            add_swap (X, i);

            for (int j = i; sorted [j].second != i; j = sorted [j].second)
                add_swap (j, sorted [j].second);

            for (int j = i; cycle [j] != -1; j = sorted [j].second)
                cycle [j] = -1;

            int j = i;

            while (sorted [j].second != i)
                j = sorted [j].second;

            add_swap (X, j);
        }

    for (int j = X; sorted [j].second != X; j = sorted [j].second)
    {
        add_swap (j, sorted [j].second);
        cycle [j] = -1;
    }

    printf ("%d\n", (int) swaps.size ());

    for (int i = 0; i < (int) swaps.size (); i++)
    {
        printf ("%d %d\n", swaps [i].first + 1, swaps [i].second + 1);
        assert (lucky (array [swaps [i].first]) || lucky (array [swaps [i].second]));
        swap (array [swaps [i].first], array [swaps [i].second]);
    }

    for (int i = 0; i + 1 < N; i++)
        assert (array [i] <= array [i + 1]);

    return 0;
}