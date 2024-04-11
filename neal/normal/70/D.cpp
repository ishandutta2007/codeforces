#include <cstdio>
#include <map>
using namespace std;

struct online_hull
{
    map <int, int> points;
    long long area;

    inline online_hull ()
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

// Note: all areas are signed and doubled. For triangles, clockwise is positive.

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

    inline bool insert (int x, int y)
    {
        if (points.find (x) != points.end ())
        {
// change to >= for lower hull 
            if (y <= points [x])
                return false;

            area -= triarea (points.find (x));
            points.erase (x);
        }

        map <int, int> :: iterator it = points.insert (make_pair (x, y)).first;

        if (bad (it))
        {
            points.erase (it);
            return false;
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

        return true;
    }

    inline bool contains (int x, int y)
    {
        if (points.empty ())
            return false;

        map <int, int> :: iterator first = points.begin (), last = prev (points.end ());

        if (x < first->first || x > last->first)
            return false;

        if (x == first->first)
            return y <= first->second;

        if (x == last->first)
            return y <= last->second;

        map <int, int> :: iterator it = points.lower_bound (x), p = prev (it);
        return triarea (p->first, p->second, x, y, it->first, it->second) <= 0;
    }
};

int Q;
online_hull upper, lower;

int main ()
{
    scanf ("%d", &Q);

    while (Q-- > 0)
    {
        int type, x, y; scanf ("%d %d %d", &type, &x, &y);

        if (type == 1)
        {
            upper.insert (x, y);
            lower.insert (x, -y);
        }
        else if (type == 2)
            puts ((upper.contains (x, y) && lower.contains (x, -y)) ? "YES" : "NO");
    }

    return 0;
}