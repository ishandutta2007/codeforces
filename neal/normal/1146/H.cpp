#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct point {
    long long x, y;
    int first, second;

    point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}

    point operator-(const point &other) const {
        return point(x - other.x, y - other.y);
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

// Sort in increasing order of angle to the x-axis.
bool angle_compare(const point &a, const point &b) {
    if (a.top_half() ^ b.top_half())
        return a.top_half();

    return cross(a, b) > 0;
}


const int N_MAX = 305, GOAL = 5;

int N;
vector<point> points;
vector<point> segments;
long long dp[N_MAX][N_MAX][GOAL + 1];

int main() {
    cin >> N;
    points.resize(N);

    for (point &p : points)
        cin >> p.x >> p.y;

    sort(points.begin(), points.end(), yx_compare);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j) {
                segments.push_back(points[j] - points[i]);
                segments.back().first = i;
                segments.back().second = j;
            }

    sort(segments.begin(), segments.end(), angle_compare);
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++)
        dp[i][i][0] = 1;

    for (auto &segment : segments)
        for (int i = 0; i <= min(segment.first, segment.second); i++)
            for (int k = 0; k < GOAL; k++)
                dp[segment.second][i][k + 1] += dp[segment.first][i][k];

    long long total = 0;

    for (int i = 0; i < N; i++)
        total += dp[i][i][GOAL];

    cout << total << '\n';
}