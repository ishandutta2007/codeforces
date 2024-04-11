#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct point {
    long long x, y;
    int index;

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

bool left_turn(const point &a, const point &b, const point &c) {
    return cross(b - a, c - b) > 0;
}

// Sort in increasing order of y, with ties broken in increasing order of x.
bool yx_compare(const point &a, const point &b) {
    return (b - a).top_half();
}

// Sort in increasing order of angle to the x-axis.
bool angle_compare(const point &a, const point &b) {
    if (a.top_half() ^ b.top_half())
        return a.top_half();

    return cross(a, b) > 0;
}


int N;
vector<point> points;
string S;
vector<int> order;
vector<bool> available;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    points.resize(N);

    for (point &p : points)
        cin >> p.x >> p.y;

    for (int i = 0; i < N; i++)
        points[i].index = i;

    cin >> S;

    sort(points.begin(), points.end(), yx_compare);
    vector<point> subtracted;

    for (int i = 1; i < N; i++) {
        subtracted.push_back(points[i] - points[0]);
        subtracted.back().index = i;
    }

    sort(subtracted.begin(), subtracted.end(), angle_compare);
    order.push_back(0);

    if (S[0] == 'L')
        order.push_back(subtracted.front().index);
    else
        order.push_back(subtracted.back().index);

    available.assign(N, true);
    available[order[0]] = available[order[1]] = false;

    for (int i = 1; i < N - 2; i++) {
        // segment: order[i - 1] -> order[i]
        // point a = points[order[i - 1]];
        point b = points[order[i]];
        int choice = -1;

        for (int c = 0; c < N; c++)
            if (available[c]) {
                if (choice < 0) {
                    choice = c;
                    continue;
                }

                if ((S[i] == 'L') ^ left_turn(b, points[choice], points[c]))
                    choice = c;
            }

        order.push_back(choice);
        available[choice] = false;
    }

    for (int i = 0; i < N; i++)
        if (available[i])
            order.push_back(i);

    assert((int) order.size() == N);

    for (int i = 0; i < N; i++)
        cout << points[order[i]].index + 1 << (i < N - 1 ? ' ' : '\n');
}