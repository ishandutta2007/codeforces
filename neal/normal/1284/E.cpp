#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

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

const bool CHECK_OVERFLOW64 = false;

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

// Returns the signed, doubled area formed by three points in a triangle. Positive when a -> b -> c is a left turn.
long long area_signed_doubled(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a);
}

long double distance_to_line(const point &p, const point &a, const point &b) {
    assert(a != b);
    return abs(area_signed_doubled(p, a, b)) / (a - b).dist();
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
vector<point> points;

long long choose3(long long n) {
    return n * (n - 1) * (n - 2) / 6;
}

long long choose4(long long n) {
    return n * (n - 1) * (n - 2) * (n - 3) / 24;
}

long long solve(int index) {
    vector<point> my_points;

    for (int i = 0; i < N; i++)
        if (i != index)
            my_points.push_back(points[i] - points[index]);

    sort(my_points.begin(), my_points.end(), angle_compare);
    int n = N - 1;

    for (int i = 0; i < n; i++)
        my_points.push_back(my_points[i]);

    long long sum = 0;

    for (int i = 0, j = 0; i < n; i++) {
        while (j < i + n && left_turn_lenient(my_points[j], point(0, 0), my_points[i]))
            j++;

        sum += choose3(j - i - 1);
    }

    return choose4(n) - sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    points.resize(N);

    for (point &p : points)
        cin >> p.x >> p.y;

    long long total = 0;

    for (int i = 0; i < N; i++)
        total += solve(i);

    cout << total << '\n';
}