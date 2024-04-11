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

    bool operator==(const point &other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const point &other) const {
        return !(*this == other);
    }

    point operator-() const {
        return point(-x, -y);
    }

    bool top_half() const {
        return y > 0 || (y == 0 && x > 0);
    }
};

long long cross(const point &a, const point &b) {
    return (long long) a.x * b.y - (long long) b.x * a.y;
}

// Sort in increasing order of y, with ties broken in increasing order of x.
bool yx_compare(const point &a, const point &b) {
    return (b - a).top_half();
}


struct line {
    long long a, b, c;

    void simplify() {
        long long g = abs(__gcd(a, b));
        assert(c % g == 0);
        a /= g;
        b /= g;
        c /= g;
    }

    bool operator<(const line &other) const {
        long long cp = cross(point(a, b), point(other.a, other.b));

        if (cp != 0)
            return cp > 0;

        return c < other.c;
    }

    bool same_slope(const line &other) const {
        return cross(point(a, b), point(other.a, other.b)) == 0;
    }

    bool operator==(const line &other) const {
        return same_slope(other) && c == other.c;
    }
};

int N;
vector<point> poles;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    poles.resize(N);

    for (point &p : poles)
        cin >> p.x >> p.y;

    sort(poles.begin(), poles.end(), yx_compare);
    vector<line> lines;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            line ln;
            ln.a = poles[j].y - poles[i].y;
            ln.b = poles[i].x - poles[j].x;
            ln.c = cross(poles[i], poles[j]);
            ln.simplify();
            lines.push_back(ln);
        }

    sort(lines.begin(), lines.end());
    lines.resize(unique(lines.begin(), lines.end()) - lines.begin());
    int L = lines.size();
    long long answer = (long long) L * (L - 1) / 2;

    for (int i = 0, j = 0; i < L; i = j) {
        while (j < L && lines[i].same_slope(lines[j]))
            j++;

        answer -= (long long) (j - i) * (j - i - 1) / 2;
    }

    cout << answer << '\n';
}