#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct safe_hash32 {
    static unsigned hash32(unsigned x) {
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        return x ^ (x >> 16);
    }

    size_t operator()(unsigned x) const {
        static const unsigned FIXED_RANDOM = hash32(
            chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));
        return hash32(x ^ FIXED_RANDOM);
    }
};

template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    vector<T> tree;

    fenwick_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.assign(tree_n + 1, 0);
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);

        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    // Returns the sum of the range [0, count).
    T query(int count) const {
        assert(count <= tree_n);
        T sum = 0;

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }
};

struct query {
    int start, end, index, answer;

    bool operator<(const query &other) const {
        return start < other.start;
    }
};

vector<int> solve_count_distinct(vector<int> A, vector<query> queries, int max_value = -1) {
    int N = A.size(), Q = queries.size();

    for (int q = 0; q < Q; q++)
        queries[q].index = q;

    sort(queries.begin(), queries.end());
    fenwick_tree<int> tree(N);

    // Sanity check to make sure I'm not accidentally providing a large value.
    if (max_value > 1e7 + 5)
        max_value = -1;

    // We will use either a hash table or an array depending on whether max_value is provided.
    gp_hash_table<int, int, safe_hash32> seen_table;
    vector<int> seen_array(max_value + 1, -1);

    for (int i = N - 1, q = Q - 1; i >= 0; i--) {
        tree.update(i, +1);

        int last_seen;

        if (max_value < 0)
            last_seen = seen_table.find(A[i]) != seen_table.end() ? seen_table[A[i]] : -1;
        else
            last_seen = seen_array[A[i]];

        if (last_seen >= 0)
            tree.update(last_seen, -1);

        if (max_value < 0)
            seen_table[A[i]] = i;
        else
            seen_array[A[i]] = i;

        while (q >= 0 && queries[q].start == i) {
            queries[q].answer = tree.query(queries[q].end);
            q--;
        }
    }

    vector<int> answers(Q, 0);

    for (query &qry : queries)
        answers[qry.index] = qry.answer;

    return answers;
}

struct point {
    long long x, y;
    int index;

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

const bool CHECK_OVERFLOW64 = true;

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

    return cross(a, b) > 0;
}


int N, S;
vector<int> polygon_index;
vector<point> polygon_sides;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    polygon_index.resize(N + 1);

    for (int i = 0; i < N; i++) {
        polygon_index[i] = polygon_sides.size();
        int k;
        cin >> k;
        vector<point> polygon(k);

        for (int j = 0; j < k; j++)
            cin >> polygon[j].x >> polygon[j].y;

        for (int j = 0; j < k; j++)
            polygon_sides.push_back(polygon[(j + 1) % k] - polygon[j]);
    }

    S = polygon_sides.size();
    polygon_index[N] = S;

    for (int i = 0; i < S; i++)
        polygon_sides[i].index = i;

    sort(polygon_sides.begin(), polygon_sides.end(), angle_compare);
    vector<int> values(S);
    int value = 0;

    for (int i = 0, j = 0; i < S; i = j) {
        while (j < S && cross_sign(polygon_sides[i], polygon_sides[j]) == 0) {
            values[polygon_sides[j].index] = value;
            j++;
        }

        value++;
    }

    int Q;
    cin >> Q;
    vector<query> queries(Q);

    for (query &qry : queries) {
        cin >> qry.start >> qry.end;
        qry.start--;
        qry.start = polygon_index[qry.start];
        qry.end = polygon_index[qry.end];
    }

    vector<int> answers = solve_count_distinct(values, queries, value);

    for (int answer : answers)
        cout << answer << '\n';
}