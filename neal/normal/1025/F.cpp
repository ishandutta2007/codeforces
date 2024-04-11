#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct point {
    int x, y;

    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

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

    bool top_half() const {
        return make_pair(y, x) > make_pair(0, 0);
    }
};

long long cross(const point &a, const point &b) {
    return (long long) a.x * b.y - (long long) b.x * a.y;
}

int N;
vector<point> start_points;

long long count_at_point(int index) {
    vector<point> points;
    int P = N - 1;

    for (int i = 0; i < N; i++)
        if (i != index)
            points.push_back(start_points[i] - start_points[index]);

    sort(points.begin(), points.end(), [](const point &a, const point &b) {
        if (a.top_half() ^ b.top_half())
            return a.top_half();

        return cross(a, b) > 0;
    });

    for (int i = 0; i < P; i++)
        points.push_back(points[i]);

    long long count = 0;

    for (int i = 0, j = 0; i < P; i++) {
        while (j < i + P && cross(points[i], points[j]) >= 0)
            j++;

        long long a = j - i - 1;
        long long b = P - 1 - a;
        assert(a >= 0 && b >= 0);
        count += a * (a - 1) / 2 * b * (b - 1) / 2;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    start_points.resize(N);

    for (int i = 0; i < N; i++)
        cin >> start_points[i].x >> start_points[i].y;

    long long total = 0;

    for (int i = 0; i < N; i++)
        total += count_at_point(i);

    assert(total % 2 == 0);
    cout << total / 2 << '\n';
    return 0;
}