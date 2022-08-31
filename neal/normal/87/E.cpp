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

struct hull
{
    map <int, int> points;
    long long area;

    inline hull ()
    {
        points.clear ();
        area = 0;
    }

    inline map <int, int> :: iterator prev (map <int, int> :: iterator it)
    {
        return it == points.begin () ? it : --it;
    }

    inline map <int, int> :: iterator next (map <int, int> :: iterator it)
    {
        return it == points.end () ? it : ++it;
    }

// note: all areas are signed and doubled

    inline long long traparea (long long x1, long long y1, long long x2, long long y2)
    {
        return (x2 - x1) * (y1 + y2);
    }

    inline long long triarea (long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
    {
        return traparea (x1, y1, x2, y2) + traparea (x2, y2, x3, y3) + traparea (x3, y3, x1, y1);
    }

    inline long long traparea (map <int, int> :: iterator a, map <int, int> :: iterator b)
    {
        return traparea (a->first, a->second, b->first, b->second);
    }

    inline long long triarea (map <int, int> :: iterator it)
    {
        long long sum = 0;

        if (it != points.begin ()) sum += traparea (prev (it), it);
        if (next (it) != points.end ()) sum += traparea (it, next (it));
        if (it != points.begin () && next (it) != points.end ()) sum += traparea (next (it), prev (it));

        return sum;
    }

    inline bool bad (map <int, int> :: iterator it)
    {
        if (points.size () < 3 || it == points.begin () || next (it) == points.end ())
            return false;

// change to >= for lower hull
        return triarea (it) <= 0;
    }

    inline void insert (int x, int y)
    {
        if (points.find (x) != points.end ())
        {
// change to >= for lower hull 
            if (y <= points [x])
                return;

            area -= triarea (points.lower_bound (x));
            points.erase (x);
        }

        map <int, int> :: iterator it = points.insert (make_pair (x, y)).first;

        if (bad (it))
        {
            points.erase (it);
            return;
        }

        area += triarea (it);

        while (bad (prev (it)))
        {
            area -= triarea (prev (it));
            points.erase (prev (it));
        }

        while (bad (next (it)))
        {
            area -= triarea (next (it));
            points.erase (next (it));
        }
    }

    inline bool contains (int x, int y)
    {
        map <int, int> :: iterator first = points.begin (), last = prev (points.end ());

        if (x < first->first || x > last->first)
            return false;

        if (x == first->first)
            return y <= first->second;

        if (x == last->first)
            return y <= last->second;

        map <int, int> :: iterator it = points.lower_bound (x), p = prev (it);
        int x1 = p->first, y1 = p->second, x2 = it->first, y2 = it->second;

        return (long long) (y - y1) * (x2 - x1) <= (long long) (x - x1) * (y2 - y1);
    }
};

typedef complex <int> point;
typedef vector <point> polygon;

template <typename T> inline pair <T, T> to_pair (complex <T> x)
{
    return make_pair (x.real (), x.imag ());
}

inline long long cross (point a, point b)
{
    return (long long) a.real () * b.imag () - (long long) b.real () * a.imag ();
}

polygon minkowski_sum (polygon a, polygon b)
{
    int n = a.size (), m = b.size ();
    int aind = -1, bind = -1;

    for (int i = 0; i < n; i++)
        if (aind == -1 || to_pair (a [i]) < to_pair (a [aind]))
            aind = i;

    for (int i = 0; i < m; i++)
        if (bind == -1 || to_pair (b [i]) < to_pair (b [bind]))
            bind = i;

    polygon sum;
    sum.reserve (n + m);

    bool alooped = false, blooped = false;
    int i = aind, j = bind;

    while (!(i == aind && alooped) || !(j == bind && blooped))
    {
        point pa = a [(i + 1) % n] - a [i], pb = b [(j + 1) % m] - b [j];

        if (!(i == aind && alooped) && ((j == bind && blooped) || cross (pa, pb) > 0))
        {
            sum.push_back (a [i] + b [j] + pa);
            i = (i + 1) % n;
            alooped |= i == 0;
        }
        else
        {
            sum.push_back (a [i] + b [j] + pb);
            j = (j + 1) % m;
            blooped |= j == 0;
        }
    }

    return sum;
}

polygon A, B, C;

void input (polygon &P)
{
    int n; scanf ("%d", &n);

    for (int x, y, i = 0; i < n; i++)
    {
        scanf ("%d %d", &x, &y);
        P.push_back (point (x, y));
    }
}

hull upper, lower;

int main ()
{
    input (A);
    input (B);
    input (C);

    polygon X = minkowski_sum (A, B);
    X = minkowski_sum (X, C);

    for (int i = 0; i < (int) X.size (); i++)
    {
        upper.insert (X [i].real (), X [i].imag ());
        lower.insert (X [i].real (), -X [i].imag ());
    }

    int M; scanf ("%d", &M);

    for (int x, y, i = 0; i < M; i++)
    {
        scanf ("%d %d", &x, &y);
        puts (upper.contains (3 * x, 3 * y) && lower.contains (3 * x, -3 * y) ? "YES" : "NO");
    }

    return 0;
}