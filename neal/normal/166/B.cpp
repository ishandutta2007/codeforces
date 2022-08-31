#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

struct upper_hull {
    map<int, int> points;
    long long area;

    upper_hull() {
        points.clear();
        area = 0;
    }

    map<int, int>::iterator prev(map<int, int>::iterator it) const {
        return it == points.begin() ? it : --it;
    }

    map<int, int>::iterator next(map<int, int>::iterator it) const {
        return it == points.end() ? it : ++it;
    }

    long long cross(long long x1, long long y1, long long x2, long long y2) const {
        return x1 * y2 - x2 * y1;
    }

    // Note: all areas are signed and doubled. For triangles, clockwise (not counter-clockwise) is positive.

    long long trapezoid_area(long long x1, long long y1, long long x2, long long y2) const {
        return (x2 - x1) * (y1 + y2);
    }

    long long trapezoid_area(pair<int, int> p1, pair<int, int> p2) const {
        return trapezoid_area(p1.first, p1.second, p2.first, p2.second);
    }

    long long triangle_area(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) const {
        return cross(x2 - x1, y2 - y1, x2 - x3, y2 - y3);
    }

    long long triangle_area(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
        return triangle_area(p1.first, p1.second, p2.first, p2.second, p3.first, p3.second);
    }

    // Gets the area that a point is responsible for; that is, how much area would be lost if the point were removed.
    long long point_area(map<int, int>::iterator it) {
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

    bool bad(map<int, int>::iterator it) {
        if (it == points.begin() || next(it) == points.end())
            return false;

        // True if the three points form a left turn or line up straight.
        return point_area(it) <= 0;
    }

    void erase(map<int, int>::iterator it) {
        area -= point_area(it);
        points.erase(it);
    }

    bool insert(int x, int y) {
        if (points.find(x) != points.end()) {
            if (y <= points[x])
                return false;

            erase(points.find(x));
        }

        map<int, int>::iterator it = points.insert(make_pair(x, y)).first;

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
    int contains(int x, int y) {
        if (points.empty())
            return -1;

        map<int, int>::iterator first = points.begin(), last = prev(points.end());

        if (x < first->first || x > last->first)
            return -1;

        if (x == first->first)
            return y <= first->second ? 0 : -1;

        if (x == last->first)
            return y <= last->second ? 0 : -1;

        map<int, int>::iterator it = points.lower_bound(x);
        long long a = triangle_area(*prev(it), make_pair(x, y), *it);
        return a == 0 ? 0 : (a > 0 ? -1 : 1);
    }
};

// The combined hull with both upper and lower.
struct online_hull {
    upper_hull upper, lower;

    long long get_area_doubled() const {
        return upper.area + lower.area;
    }

    bool insert(int x, int y) {
        bool upper_insert = upper.insert(x, y);
        bool lower_insert = lower.insert(x, -y);
        return upper_insert || lower_insert;
    }

    int contains(int x, int y) {
        int upper_contains = upper.contains(x, y);
        int lower_contains = lower.contains(x, -y);
        return min(upper_contains, lower_contains);
    }
};

online_hull hull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        assert(hull.insert(x, y));
    }

    int m;
    cin >> m;

    bool inside = true;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        if (hull.contains(x, y) <= 0)
            inside = false;
    }

    cout << (inside ? "YES" : "NO") << '\n';
    return 0;
}