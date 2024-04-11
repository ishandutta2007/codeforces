// Solution to https://codeforces.com/contest/1175/problem/G
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct point {
    int x, y;

    point() : x(0), y(0) {}

    point(int _x, int _y) : x(_x), y(_y) {}
};

// reverse_monotonic_dp_hull enables you to do the following two operations in amortized O(1) time:
// 1. Insert a pair (a_i, b_i) into the structure. a_i must be non-decreasing.
// 2. For any value of x, query the maximum value of a_i * x + b_i. x must be non-increasing.
// All values a_i, b_i, and x can be positive or negative.
struct reverse_monotonic_dp_hull {
    vector<point> points;

    int size() const {
        return (int) points.size();
    }

    void clear() {
        points.clear();
        prev_x = INF;
    }

    static int floor_div(int a, int b) {
        return a / b - ((a ^ b) < 0 && a % b != 0);
    }

    static bool bad_middle(const point &a, const point &b, const point &c) {
        // This checks whether the x-value where b becomes better than a comes after the x-value where c becomes better
        // than a. It's fine to round down here if we will only query integer x-values. (C++ division rounds to zero)
        return floor_div(a.y - b.y, b.x - a.x) >= floor_div(b.y - c.y, c.x - b.x);
    }

    void insert(const point &p) {
        assert(size() == 0 || p.x >= points.back().x);

        if (size() > 0 && p.x == points.back().x) {
            if (p.y <= points.back().y)
                return;

            points.pop_back();
        }

        while (size() >= 2 && bad_middle(points[points.size() - 2], points.back(), p))
            points.pop_back();

        points.push_back(p);
    }

    void insert(int a, int b) {
        insert(point(a, b));
    }

    int prev_x = INF;

    // Queries the maximum value of ax + b.
    int query(int x) {
        assert(x <= prev_x);
        prev_x = x;

        while (size() >= 2 && x * (points.back().x - points[size() - 2].x) <= points[size() - 2].y - points.back().y)
            points.pop_back();

        return points.back().x * x + points.back().y;
    }
};


int N, K;
vector<int> A;
vector<int> dp, next_dp;
vector<int> left_max, right_max;

const int QUADRATIC_CUTOFF = 40;

void update(int start, int end) {
    if (end - start <= QUADRATIC_CUTOFF) {
        for (int i = start; i < end; i++) {
            int most = -INF;

            for (int j = i + 1; j <= end; j++) {
                most = max(most, A[j - 1]);
                next_dp[j] = min(next_dp[j], dp[i] + (j - i) * most);
            }
        }

        return;
    }

    int mid = (start + end) / 2;
    update(start, mid);

    left_max[mid] = right_max[mid] = -INF;

    for (int i = mid - 1; i >= start; i--)
        left_max[i] = max(left_max[i + 1], A[i]);

    for (int i = mid; i < end; i++)
        right_max[i + 1] = max(right_max[i], A[i]);

    // Overall next_dp[right] = min_{left} (dp[left] + (right - left) * max(left_max[left], right_max[right])).
    reverse_monotonic_dp_hull hull;

    // Minimize dp[left] + (right - left) * right_max[right]
    // = dp[left] - left * right_max[right] + right * right_max[right].
    for (int right = mid + 1, left = mid; right <= end; right++) {
        while (left >= start && right_max[right] >= left_max[left]) {
            hull.insert(-left, -dp[left]);
            left--;
        }

        if (hull.size() > 0)
            next_dp[right] = min(next_dp[right], -hull.query(-right_max[right]) + right * right_max[right]);
    }

    hull.clear();

    // Minimize dp[left] + (right - left) * left_max[left]
    // = dp[left] - left * left_max[left] + right * left_max[left].
    for (int right = end, left = start; right > mid; right--) {
        while (left <= mid && left_max[left] >= right_max[right]) {
            hull.insert(-left_max[left], left * left_max[left] - dp[left]);
            left++;
        }

        if (hull.size() > 0)
            next_dp[right] = min(next_dp[right], -hull.query(right));
    }

    update(mid + 1, end);
}

void update_dp() {
    left_max.assign(N + 1, -INF);
    right_max.assign(N + 1, -INF);
    next_dp.assign(N + 1, INF);
    update(0, N);
    dp = next_dp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    dp.assign(N + 1, INF);
    dp[0] = 0;

    for (int k = 0; k < K; k++)
        update_dp();

    cout << dp[N] << '\n';
}