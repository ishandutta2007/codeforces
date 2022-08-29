#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct point {
    int x, y;
    int index;

    point(int _x = 0, int _y = 0) : x(_x), y(_y) {
        index = -1;
    }

    point& operator+=(const point &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    point& operator-=(const point &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    point operator+(const point &other) const {
        return point(*this) += other;
    }

    point operator-(const point &other) const {
        return point(*this) -= other;
    }

    bool operator<(const point &other) const {
        return make_pair(y, x) > make_pair(other.y, other.x);
    }
};

long long cross(const point &a, const point &b) {
    return (long long) a.x * b.y - (long long) b.x * a.y;
}

long long triangle_area(const point &a, const point &b, const point &c) {
    return abs(cross(b - a, c - a));
}

struct segment {
    point p;
    int index1, index2;

    segment(const point &_p, int _index1, int _index2) : p(_p), index1(_index1), index2(_index2) {}

    bool operator<(const segment &other) const {
        return cross(p, other.p) > 0;
    }
};

int N;
long long S;
vector<point> points;
vector<segment> segments;
vector<int> location;

void yes(point a, point b, point c) {
    cout << "Yes" << '\n';
    cout << a.x << ' ' << a.y << '\n';
    cout << b.x << ' ' << b.y << '\n';
    cout << c.x << ' ' << c.y << '\n';
    assert(triangle_area(a, b, c) == 2 * S);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    points.resize(N);

    for (int i = 0; i < N; i++)
        cin >> points[i].x >> points[i].y;

    sort(points.begin(), points.end());
    location.resize(N);

    for (int i = 0; i < N; i++) {
        points[i].index = i;
        location[i] = i;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            segments.emplace_back(points[j] - points[i], i, j);

    sort(segments.begin(), segments.end());

    for (segment &s : segments) {
        int &a = location[s.index1];
        int &b = location[s.index2];
        assert(b == a - 1);

        int low = 0, high = b - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            long long area = triangle_area(points[mid], points[a], points[b]);

            if (area == 2 * S) {
                yes(points[mid], points[a], points[b]);
                return 0;
            }

            if (area > 2 * S)
                low = mid + 1;
            else
                high = mid - 1;
        }

        low = a + 1;
        high = N - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            long long area = triangle_area(points[mid], points[a], points[b]);

            if (area == 2 * S) {
                yes(points[mid], points[a], points[b]);
                return 0;
            }

            if (area > 2 * S)
                high = mid - 1;
            else
                low = mid + 1;
        }

        swap(points[a], points[b]);
        swap(a, b);
    }

    cout << "No" << '\n';
    return 0;
}