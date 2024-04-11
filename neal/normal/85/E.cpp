#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 5005, MAXC = 5005, MOD = 1000000007;

int N, X [MAXN], Y [MAXN];

bool good (int dist)
{
    bool ok1 = true, ok2 = true;
    int minx = MAXC, miny = MAXC, maxx = -MAXC, maxy = -MAXC;

    for (int i = 0; i < N; i++)
    {
        minx = min (minx, X [i]);
        maxx = max (maxx, X [i]);
        miny = min (miny, Y [i]);
        maxy = max (maxy, Y [i]);
    }

    for (int i = 0; i < N && (ok1 || ok2); i++)
    {
        if ((X [i] > minx + dist || Y [i] > miny + dist) && (X [i] < maxx - dist || Y [i] < maxy - dist)) ok1 = false;
        if ((X [i] > minx + dist || Y [i] < maxy - dist) && (X [i] < maxx - dist || Y [i] > miny + dist)) ok2 = false;
    }

    return ok1 || ok2;
}

int intersect (string a, string b)
{
    int count = 0;

    for (int i = 0; i < N; i++)
        if (a [i] == 'X' || b [i] == 'X' || a [i] + b [i] == 'A' + 'B')
            return -1;
        else if (a [i] == '?' && b [i] == '?')
            count++;

    return count;
}

string flip (string s)
{
    for (int i = 0; i < N; i++)
        if (s [i] == 'A' || s [i] == 'B')
            s [i] = 'A' + 'B' - s [i];

    return s;
}

int count_question (string s)
{
    int count = 0;

    for (int i = 0; i < N; i++)
        if (s [i] == 'X')
            return -1;
        else if (s [i] == '?')
            count++;

    return count;
}

int pow2 (int k)
{
    if (k < 0)
        return 0;

    int p = 1;

    while (k-- > 0)
        p = 2 * p % MOD;

    return p;
}

int ways (int dist)
{
    string way1 (N, '?'), way2 (N, '?');
    int minx = MAXC, miny = MAXC, maxx = -MAXC, maxy = -MAXC;

    for (int i = 0; i < N; i++)
    {
        minx = min (minx, X [i]);
        maxx = max (maxx, X [i]);
        miny = min (miny, Y [i]);
        maxy = max (maxy, Y [i]);
    }

    for (int i = 0; i < N; i++)
    {
        bool sq1, sq2; char c;

        sq1 = X [i] <= minx + dist && Y [i] <= miny + dist;
        sq2 = X [i] >= maxx - dist && Y [i] >= maxy - dist;

        if (sq1 && sq2)
            c = '?';
        else if (sq1 && !sq2)
            c = 'A';
        else if (!sq1 && sq2)
            c = 'B';
        else
            c = 'X';

        way1 [i] = c;

        sq1 = X [i] <= minx + dist && Y [i] >= maxy - dist;
        sq2 = X [i] >= maxx - dist && Y [i] <= miny + dist;

        if (sq1 && sq2)
            c = '?';
        else if (sq1 && !sq2)
            c = 'A';
        else if (!sq1 && sq2)
            c = 'B';
        else
            c = 'X';

        way2 [i] = c;
    }

    int inter = max (intersect (way1, way2), intersect (way1, flip (way2)));
    return (pow2 (count_question (way1)) + pow2 (count_question (way2)) - pow2 (inter)) % MOD;
}

int main ()
{
    scanf ("%d", &N);

    for (int x, y, i = 0; i < N; i++)
    {
        scanf ("%d %d", &x, &y);
        X [i] = x + y - MAXC;
        Y [i] = x - y;
    }

    int lo = 0, hi = 5 * MAXC;

    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;

        if (good (mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    printf ("%d\n%d\n", lo, (2 * ways (lo) % MOD + MOD) % MOD);
    return 0;
}