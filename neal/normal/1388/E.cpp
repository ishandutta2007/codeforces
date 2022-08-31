#include <algorithm>
#include <array>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct fraction {
    // CHECK_OVERFLOW64 = true can run up to 2.5 times slower (particularly on CF).
    static const bool CHECK_OVERFLOW64 = false;

    static const bool AUTO_REDUCE = false;

    static int cross_sign(const fraction &a, const fraction &b) {
        if (CHECK_OVERFLOW64) {
            long double double_value = (long double) a.numer * b.denom - (long double) b.numer * a.denom;

            if (abs(double_value) > 1e18)
                return double_value > 0 ? +1 : -1;
        }

        uint64_t uint64_value = (uint64_t) a.numer * b.denom - (uint64_t) b.numer * a.denom;

        if (uint64_value == 0)
            return 0;

        return uint64_value >> 63 ? -1 : +1;
    }

    int64_t numer, denom;

    fraction(int64_t n = 0, int64_t d = 1) : numer(n), denom(d) {
        check_denom();

        if (AUTO_REDUCE)
            reduce();
    }

    void check_denom() {
        assert(denom != 0);

        if (denom < 0) {
            numer = -numer;
            denom = -denom;
        }
    }

    void reduce() {
        int64_t g = __gcd(abs(numer), denom);
        numer /= g;
        denom /= g;
    }

    bool is_integer() const {
        return denom == 1;
    }

    friend fraction operator+(const fraction &a, const fraction &b) {
        return fraction(a.numer * b.denom + b.numer * a.denom, a.denom * b.denom);
    }

    friend fraction operator-(const fraction &a, const fraction &b) {
        return fraction(a.numer * b.denom - b.numer * a.denom, a.denom * b.denom);
    }

    friend fraction operator*(const fraction &a, const fraction &b) {
        return fraction(a.numer * b.numer, a.denom * b.denom);
    }

    friend fraction operator/(const fraction &a, const fraction &b) {
        return fraction(a.numer * b.denom, a.denom * b.numer);
    }

    fraction& operator+=(const fraction &other) { return *this = *this + other; }
    fraction& operator-=(const fraction &other) { return *this = *this - other; }
    fraction& operator*=(const fraction &other) { return *this = *this * other; }
    fraction& operator/=(const fraction &other) { return *this = *this / other; }

    fraction& operator++() { numer += denom; return *this; }
    fraction& operator--() { numer -= denom; return *this; }

    fraction operator++(int) { fraction before = *this; ++*this; return before; }
    fraction operator--(int) { fraction before = *this; --*this; return before; }

    fraction operator-() const {
        return fraction(-numer, denom);
    }

    fraction inv() const {
        return fraction(denom, numer);
    }

    bool operator==(const fraction &other) const { return cross_sign(*this, other) == 0; }
    bool operator!=(const fraction &other) const { return cross_sign(*this, other) != 0; }
    bool operator<(const fraction &other) const { return cross_sign(*this, other) < 0; }
    bool operator>(const fraction &other) const { return cross_sign(*this, other) > 0; }
    bool operator<=(const fraction &other) const { return cross_sign(*this, other) <= 0; }
    bool operator>=(const fraction &other) const { return cross_sign(*this, other) >= 0; }

    double to_double() const {
        return double(numer) / double(denom);
    }

    fraction to_abs() const {
        return fraction(abs(numer), denom);
    }

    friend ostream& operator<<(ostream& out, const fraction &frac) {
        return out << frac.numer << '/' << frac.denom;
    }
};

using my_float = double;


const my_float FLOAT_INF = 1e100;

struct point {
    my_float x, y;

    point() : x(0), y(0) {}

    point(my_float _x, my_float _y) : x(_x), y(_y) {}

    point operator-(const point &other) const {
        return point(x - other.x, y - other.y);
    }
};

my_float cross(const point &a, const point &b) {
    return a.x * b.y - b.x * a.y;
}

bool left_turn(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a) > 0;
}

// monotonic_dp_hull enables you to do the following two operations in amortized O(1) time:
// 1. Insert a pair (a_i, b_i) into the structure. a_i must be non-decreasing.
// 2. For any value of x, query the maximum value of a_i * x + b_i. x must be non-decreasing.
// All values a_i, b_i, and x can be positive or negative.
struct monotonic_dp_hull {
    vector<point> points;
    int front = 0;

    int size() const {
        return int(points.size()) - front;
    }

    void clear() {
        points.clear();
        front = 0;
        prev_x = -FLOAT_INF;
        prev_y = 1;
    }

    void insert(const point &p) {
        assert(size() == 0 || p.x >= points.back().x);

        if (size() > 0 && p.x == points.back().x) {
            if (p.y <= points.back().y)
                return;

            points.pop_back();
        }

        while (size() >= 2 && !left_turn(p, points.back(), points[points.size() - 2]))
            points.pop_back();

        points.push_back(p);
    }

    void insert(my_float a, my_float b) {
        insert(point(a, b));
    }

    my_float prev_x = -FLOAT_INF, prev_y = 1;

    // Queries the maximum value of ax + by.
    my_float query(my_float x, my_float y = 1) {
        assert(size() > 0);
        assert(prev_x == -FLOAT_INF || x * prev_y >= prev_x * y);
        prev_x = x; prev_y = y;

        while (size() >= 2 && x * (points[front + 1].x - points[front].x) >= (points[front].y - points[front + 1].y) * y)
            front++;

        return points[front].x * x + points[front].y * y;
    }
};


struct segment {
    int xl, xr, y;

    bool operator<(const segment &other) const {
        return y < other.y;
    }
};

int N;
vector<segment> segs;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cout << setprecision(16);

    cin >> N;
    segs.resize(N);

    for (segment &seg : segs)
        cin >> seg.xl >> seg.xr >> seg.y;

    sort(segs.begin(), segs.end());
    vector<pair<fraction, int>> events;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            if (segs[i].y == segs[j].y)
                continue;

            assert(segs[i].y < segs[j].y);
            int dy = segs[j].y - segs[i].y;
            fraction low = {segs[i].xl - segs[j].xr, dy};
            fraction high = {segs[i].xr - segs[j].xl, dy};
            events.emplace_back(low, +1);
            events.emplace_back(high, -1);
        }

    sort(events.begin(), events.end());
    vector<my_float> candidates;
    int counter = 0;

    for (auto &event : events) {
        bool good = counter == 0;
        counter += event.second;
        good = good || counter == 0;

        if (good)
            candidates.push_back(event.first.to_double());
    }

    if (candidates.empty())
        candidates = {0};

    sort(candidates.begin(), candidates.end());
    dbg(candidates);
    monotonic_dp_hull min_hull, max_hull;

    for (segment &seg : segs)
        max_hull.insert(seg.y, seg.xr);

    reverse(segs.begin(), segs.end());

    for (segment &seg : segs)
        min_hull.insert(-seg.y, -seg.xl);

    my_float best = 1e100;

    for (my_float d : candidates) {
        my_float low = -min_hull.query(d);
        my_float high = max_hull.query(d);
        best = min(best, high - low);
    }

    cout << best << '\n';
}