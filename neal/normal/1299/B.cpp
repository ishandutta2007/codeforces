#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const bool CHECK_OVERFLOW64 = false;

struct point {
    long long x, y;

    point() : x(0), y(0) {}

    point(long long _x, long long _y) : x(_x), y(_y) {}

    point& operator+=(const point &other) { x += other.x; y += other.y; return *this; }
    point& operator-=(const point &other) { x -= other.x; y -= other.y; return *this; }
    point& operator*=(long long mult) { x *= mult; y *= mult; return *this; }

    point operator+(const point &other) const { return point(*this) += other; }
    point operator-(const point &other) const { return point(*this) -= other; }
    point operator*(long long mult) const { return point(*this) *= mult; }

    bool operator==(const point &other) const { return x == other.x && y == other.y; }
    bool operator!=(const point &other) const { return !(*this == other); }

    point operator-() const { return point(-x, -y); }
    point rotate90() const { return point(-y, x); }

    long long norm() const {
        return (long long) x * x + (long long) y * y;
    }

    long double dist() const {
        return sqrt((long double) norm());
    }

    bool top_half() const {
        return y > 0 || (y == 0 && x > 0);
    }

    friend ostream& operator<<(ostream &stream, const point &p) {
        return stream << '(' << p.x << ", " << p.y << ')';
    }
};

long long cross(const point &a, const point &b) {
    return (long long) a.x * b.y - (long long) b.x * a.y;
}

long long dot(const point &a, const point &b) {
    return (long long) a.x * b.x + (long long) a.y * b.y;
}

int cross_sign(const point &a, const point &b) {
    if (CHECK_OVERFLOW64) {
        long double double_value = (long double) a.x * b.y - (long double) b.x * a.y;

        if (abs(double_value) > 1e18)
            return double_value > 0 ? +1 : -1;
    }

    uint64_t uint64_value = (uint64_t) a.x * b.y - (uint64_t) b.x * a.y;

    if (uint64_value == 0)
        return 0;

    return uint64_value >> 63 ? -1 : +1;
}

bool left_turn_strict(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) > 0;
}

bool left_turn_lenient(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) >= 0;
}

bool collinear(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) == 0;
}

// Returns twice the signed area formed by three points in a triangle. Positive when a -> b -> c is a left turn.
long long area_signed_2x(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a);
}

long double distance_to_line(const point &p, const point &a, const point &b) {
    assert(a != b);
    return abs(area_signed_2x(p, a, b)) / (a - b).dist();
}

long long manhattan_dist(const point &a, const point &b) {
    return (long long) abs(a.x - b.x) + abs(a.y - b.y);
}

long long infinity_norm_dist(const point &a, const point &b) {
    return max(abs(a.x - b.x), abs(a.y - b.y));
}

// Sort in increasing order of y, with ties broken in increasing order of x.
bool yx_compare(const point &a, const point &b) {
    return (b - a).top_half();
}

// Sort in increasing order of angle to the x-axis.
bool angle_compare(const point &a, const point &b) {
    if (a.top_half() ^ b.top_half())
        return a.top_half();

    return cross_sign(a, b) > 0;
}


int N;
vector<point> polygon;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    polygon.resize(N);

    for (point &p : polygon)
        cin >> p.x >> p.y;

    vector<point> rotated = polygon;

    for (int i = 0; i < N; i++) {
        rotated[i].x *= -1;
        rotated[i].y *= -1;
    }

    sort(polygon.begin(), polygon.end(), yx_compare);
    sort(rotated.begin(), rotated.end(), yx_compare);

    for (int i = 1; i < N; i++)
        if (rotated[i] - polygon[i] != rotated[0] - polygon[0]) {
            cout << "NO" << '\n';
            return 0;
        }

    cout << "YES" << '\n';
}