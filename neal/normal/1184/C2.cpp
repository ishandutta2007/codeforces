#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 300005, MAXT = 4 * MAXN;

struct point
{
    int x, y, milk;

    inline bool operator < (const point &o) const
    {
        return x < o.x;
    }
};

int N, P, PN, S, ylist [MAXN];
long long best = 0;
point cows [MAXN];
pair <long long, long long> tree [MAXT];

inline int search (int val)
{
    return lower_bound (ylist, ylist + N, val) - ylist;
}

inline int tstart (int pos)
{
    int level = 31 - __builtin_clz (pos);
    return min (pos - (1 << level) << P - level, N);
}

inline int tend (int pos)
{
    int level = 31 - __builtin_clz (pos);
    return min (pos - (1 << level) + 1 << P - level, N);
}

inline void modify (int pos, long long add)
{
    tree [pos].first += add;
    tree [pos].second += add;
}

inline void push (int pos)
{
    if (tree [pos].second != 0)
    {
        modify (2 * pos, tree [pos].second);
        modify (2 * pos + 1, tree [pos].second);
        tree [pos].second = 0;
    }
}

inline void join (int pos)
{
    tree [pos].first = max (tree [2 * pos].first, tree [2 * pos + 1].first);
}

void insert (int pos, int a, int b, long long val)
{
    int start = tstart (pos), end = tend (pos);

    if (a <= start && end <= b)
    {
        modify (pos, val);
        return;
    }

    if (pos >= PN || start >= b || a >= end)
        return;

    push (pos);
    insert (2 * pos, a, b, val);
    insert (2 * pos + 1, a, b, val);
    join (pos);
}

int main ()
{
    scanf ("%d %d", &N, &S);
    S = 2 * S + 1;
    P = 32 - __builtin_clz (N); PN = 1 << P;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        cows[i].x = x + y;
        cows[i].y = x - y;
        cows[i].milk = 1;
        ylist [i] = cows [i].y;
    }

    sort (cows, cows + N);
    sort (ylist, ylist + N);

    for (int i = 0, j = 0; j < N; i++)
    {
        while (j < N && cows [j].x < cows [i].x + S)
        {
            insert (1, search (cows [j].y), search (cows [j].y + S), cows [j].milk);
            j++;
        }

        best = max (best, tree [1].first);
        insert (1, search (cows [i].y), search (cows [i].y + S), -cows [i].milk);
    }

    printf ("%lld\n", best);

    return 0;
}