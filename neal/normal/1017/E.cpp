#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 1e5 + 5;
const int INF = 1e9 + 5;

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

    bool operator==(const point &other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const point &other) const {
        return !(*this == other);
    }
};

long long cross(const point &a, const point &b) {
    return (long long) a.x * b.y - (long long) b.x * a.y;
}

long long dot(const point &a, const point &b) {
    return (long long) a.x * b.x + (long long) a.y * b.y;
}

long long norm(const point &p) {
    return dot(p, p);
}

bool left_turn(const point &a, const point &b, const point &c) {
    return cross(b - a, c - b) > 0;
}

double dist(const point &a, const point &b) {
    return sqrt(norm(a - b));
}


struct convex_hull {
    int N, H;
    point points[N_MAX], hull[N_MAX];

    double hull_perim() {
        double perim = 0;

        for (int i = 0; i < H; i++)
            perim += dist(hull[i], hull[i + 1]);

        return perim;
    }

    long long hull_area_doubled() {
        long long area = 0;

        for (int i = 0; i < H; i++)
            area += cross(hull[i], hull[i + 1]);

        return area;
    }

    static bool graham_compare(const point &a, const point &b) {
        // True if a's angle to the x-axis is smaller than b's, or if they are collinear and a is closer to the origin.
        long long cp = cross(a, b);
        return cp > 0 || (cp == 0 && dot(a, b - a) > 0);
    }

    void graham_scan() {
        point bottom(INF, INF);
        int bottom_index = -1;

        for (int i = 0; i < N; i++)
            if (make_pair(points[i].y, points[i].x) < make_pair(bottom.y, bottom.x)) {
                bottom = points[i];
                bottom_index = i;
            }

        int n = 0;

        // Remove all duplicates of bottom.
        for (int i = 0; i < N; i++)
            if (points[i] != bottom || i == bottom_index)
                points[n++] = points[i];

        N = n;

        for (int i = 0; i < N; i++)
            points[i] -= bottom;

        swap(points[0], points[bottom_index]);
        sort(points + 1, points + N, graham_compare);

        for (int i = 0; i < N; i++)
            points[i] += bottom;

        H = 0;

        for (int i = 0; i < N; i++) {
            while (H >= 2 && !left_turn(hull[H - 2], hull[H - 1], points[i]))
                H--;

            hull[H++] = points[i];
        }

        while (H >= 3 && !left_turn(hull[H - 2], hull[H - 1], hull[0]))
            H--;

        hull[H] = hull[0];
        hull[H + 1] = hull[1];

        if (H > 1) {
            for (int i = 0; i < H; i++)
                assert(hull[i] != hull[i + 1]);
        }
    }

    vector<long long> get_sequence() {
        vector<long long> seq;

        for (int i = 0; i < H; i++) {
            seq.push_back(norm(hull[i + 1] - hull[i]));
            seq.push_back(-norm(hull[i + 2] - hull[i]));
        }

        return seq;
    }
};

convex_hull engines[2];

template<typename T>
bool kmp_cyclic(vector<T> sequence, const vector<T> &pattern) {
    int n = sequence.size(), m = pattern.size();

    if (n != m)
        return false;

    for (int i = 0; i < n; i++)
        sequence.push_back(sequence[i]);

    n *= 2;
    vector<int> fail(m + 1, 0);
    int p = 0;

    for (int i = 1; i < m; i++) {
        while (p > 0 && pattern[p] != pattern[i])
            p = fail[p];

        if (pattern[p] == pattern[i])
            p++;

        fail[i + 1] = p;
    }

    p = 0;

    for (int i = 0; i < n; i++) {
        while (p > 0 && pattern[p] != sequence[i])
            p = fail[p];

        if (pattern[p] == sequence[i])
            p++;

        if (p == m) {
            p = fail[p];
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> engines[0].N >> engines[1].N;

    for (int e = 0; e < 2; e++)
        for (int i = 0; i < engines[e].N; i++)
            cin >> engines[e].points[i].x >> engines[e].points[i].y;

    engines[0].graham_scan();
    engines[1].graham_scan();

    bool isomorphic = kmp_cyclic(engines[0].get_sequence(), engines[1].get_sequence());
    cout << (isomorphic ? "YES" : "NO") << '\n';
    return 0;
}