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

const int MAXM = 100005, MOD = 1000000007;

struct bus
{
    int start, end;

    inline bool operator < (const bus &o) const
    {
        return end < o.end || (end == o.end && start < o.start);
    }
};

int N, M, dp [MAXM], tree [2 * MAXM];
bus buses [MAXM];
vector <int> locations;

inline int get_index (int x)
{
    return lower_bound (locations.begin (), locations.end (), x) - locations.begin ();
}

int tree_total = 0;

// [x, inf)
inline int query (int x)
{
    int sum = 0;

    for (int i = get_index (x); i > 0; i -= i & -i)
        sum = (sum + tree [i]) % MOD;

    return (tree_total - sum % MOD + MOD) % MOD;
}

inline void update (int x, int value)
{
    tree_total = (tree_total + value) % MOD;

    for (int i = get_index (x) + 1; i <= (int) locations.size (); i += i & -i)
        tree [i] = (tree [i] + value) % MOD;
}

int main ()
{
    scanf ("%d %d", &N, &M);
    M += 2;

    for (int i = 0; i < M; i++)
    {
        if (i < M - 2)
            scanf ("%d %d", &buses [i].start, &buses [i].end);
        else if (i == M - 2)
        {
            buses [i].start = -1;
            buses [i].end = 0;
        }
        else if (i == M - 1)
        {
            buses [i].start = N;
            buses [i].end = N + 1;
        }

        locations.push_back (buses [i].start);
        locations.push_back (buses [i].end);
    }

    sort (buses, buses + M);
    sort (locations.begin (), locations.end ());
    locations.resize (unique (locations.begin (), locations.end ()) - locations.begin ());
    dp [0] = 1;
    update (buses [0].end, dp [0]);

    for (int i = 1, j = i; i < M; i = j)
    {
        while (j < M && buses [i].end == buses [j].end)
            j++;

        for (int k = i; k < j; k++)
            dp [k] = query (buses [k].start);

        for (int k = i; k < j; k++)
            update (buses [k].end, dp [k]);
    }

    printf ("%d\n", dp [M - 1]);
    return 0;
}