#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

using point_t = long long;

struct upper_hull {
    map<point_t, point_t> points;
    long long area = 0;

    map<point_t, point_t>::iterator prev(map<point_t, point_t>::iterator it) const {
        return it == points.begin() ? it : --it;
    }

    map<point_t, point_t>::iterator next(map<point_t, point_t>::iterator it) const {
        return it == points.end() ? it : ++it;
    }

    long long cross(point_t x1, point_t y1, point_t x2, point_t y2) const {
        return (long long) x1 * y2 - (long long) x2 * y1;
    }

    // Note: all areas are signed and doubled. For triangles, clockwise (not counter-clockwise) is positive.

    long long trapezoid_area(point_t x1, point_t y1, point_t x2, point_t y2) const {
        return (long long) (x2 - x1) * (y1 + y2);
    }

    long long trapezoid_area(pair<point_t, point_t> p1, pair<point_t, point_t> p2) const {
        return trapezoid_area(p1.first, p1.second, p2.first, p2.second);
    }

    long long triangle_area(point_t x1, point_t y1, point_t x2, point_t y2, point_t x3, point_t y3) const {
        return cross(x2 - x1, y2 - y1, x2 - x3, y2 - y3);
    }

    long long triangle_area(pair<point_t, point_t> p1, pair<point_t, point_t> p2, pair<point_t, point_t> p3) const {
        return triangle_area(p1.first, p1.second, p2.first, p2.second, p3.first, p3.second);
    }

    // Gets the area that a point is responsible for; that is, how much area would be lost if the point were removed.
    long long point_area(map<point_t, point_t>::iterator it) {
        bool has_prev = it != points.begin();
        bool has_next = next(it) != points.end();

        if (has_prev && has_next)
            return triangle_area(*prev(it), *it, *next(it));

        long long sum = 0;

        if (has_prev)
            sum += trapezoid_area(*prev(it), *it);

        if (has_next)
            sum += trapezoid_area(*it, *next(it));

        return sum;
    }

    bool bad(map<point_t, point_t>::iterator it) {
        if (it == points.begin() || next(it) == points.end())
            return false;

        // True if the three points form a left turn or line up straight.
        return point_area(it) <= 0;
    }

    void erase(map<point_t, point_t>::iterator it) {
        area -= point_area(it);
        points.erase(it);
    }

    bool insert(point_t x, point_t y) {
        if (points.find(x) != points.end()) {
            if (y <= points[x])
                return false;

            erase(points.find(x));
        }

        map<point_t, point_t>::iterator it = points.insert(make_pair(x, y)).first;

        if (bad(it)) {
            points.erase(it);
            return false;
        }

        area += point_area(it);

        while (bad(prev(it)))
            erase(prev(it));

        while (bad(next(it)))
            erase(next(it));

        return true;
    }

    // Returns 1 for strictly contained, 0 for on the border, and -1 for not contained.
    int contains(point_t x, point_t y) {
        if (points.empty())
            return -1;

        map<point_t, point_t>::iterator first = points.begin(), last = prev(points.end());

        if (x < first->first || x > last->first)
            return -1;

        if (x == first->first)
            return y <= first->second ? 0 : -1;

        if (x == last->first)
            return y <= last->second ? 0 : -1;

        map<point_t, point_t>::iterator it = points.lower_bound(x);
        long long a = triangle_area(*prev(it), make_pair(x, y), *it);
        return a == 0 ? 0 : (a > 0 ? -1 : 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    upper_hull hull;

    while (N-- > 0) {
        long long x, y;
        cin >> x >> y;
        hull.insert(x, y - x * x);
    }

    cout << hull.points.size() - 1 << '\n';
}