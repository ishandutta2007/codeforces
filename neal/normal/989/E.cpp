#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const bool CHECK_OVERFLOW64 = false;

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

using matrix_float = double;

struct float_column_vector {
    int rows;
    vector<matrix_float> values;

    float_column_vector(int _rows = 0) {
        init(_rows);
    }

    template<typename T>
    float_column_vector(const vector<T> &v) {
        init(v);
    }

    void init(int _rows) {
        rows = _rows;
        values.assign(rows, 0);
    }

    template<typename T>
    void init(const vector<T> &v) {
        rows = v.size();
        values.resize(rows);

        for (int i = 0; i < rows; i++)
            values[i] = v[i];
    }

    matrix_float& operator[](int index) { return values[index]; }
    const matrix_float& operator[](int index) const { return values[index]; }
};

// Warning: very inefficient for many small matrices of fixed size. For that, use float_matrix_fixed_size.cc instead.
struct float_matrix {
    int rows, cols;
    vector<vector<matrix_float>> values;

    float_matrix(int _rows = 0, int _cols = -1) {
        init(_rows, _cols);
    }

    template<typename T>
    float_matrix(const vector<vector<T>> &v) {
        init(v);
    }

    void init(int _rows, int _cols = -1) {
        rows = _rows;
        cols = _cols < 0 ? rows : _cols;
        values.assign(rows, vector<matrix_float>(cols, 0));
    }

    template<typename T>
    void init(const vector<vector<T>> &v) {
        rows = v.size();
        cols = v.empty() ? 0 : v[0].size();
        values.assign(rows, vector<matrix_float>(cols, 0));

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                values[i][j] = v[i][j];
    }

    vector<matrix_float>& operator[](int index) { return values[index]; }
    const vector<matrix_float>& operator[](int index) const { return values[index]; }

    bool is_square() const {
        return rows == cols;
    }

    void make_identity() {
        assert(is_square());

        for (int i = 0; i < rows; i++) {
            values[i].assign(cols, 0);
            values[i][i] = 1;
        }
    }

    float_matrix operator*(const float_matrix &other) const {
        assert(cols == other.rows);
        float_matrix product(rows, other.cols);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (values[i][j] != 0)
                    for (int k = 0; k < other.cols; k++)
                        product[i][k] += values[i][j] * other[j][k];

        return product;
    }

    float_matrix& operator*=(const float_matrix &other) {
        assert(other.is_square() && cols == other.rows);
        return *this = *this * other;
    }

    float_column_vector operator*(const float_column_vector &column) const {
        assert(cols == column.rows);
        float_column_vector product(rows);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                product[i] += values[i][j] * column[j];

        return product;
    }

    float_matrix power(long long p) const {
        assert(p >= 0);
        assert(is_square());

        float_matrix m = *this;
        float_matrix result(rows);
        result.make_identity();

        while (p > 0) {
            if (p & 1)
                result *= m;

            p >>= 1;

            if (p > 0)
                m *= m;
        }

        return result;
    }

    void print() const {
        cout << rows << ' ' << cols << '\n';

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cout << values[i][j] << (j < cols - 1 ? ' ' : '\n');
    }
};


int N, Q, L;
vector<point> points;
vector<vector<int>> lines;
vector<int> line_count;
vector<float_matrix> transition;

void generate_lines() {
    sort(points.begin(), points.end(), yx_compare);
    vector<map<pair<int, int>, int>> line_index(N);

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            point delta = points[j] - points[i];
            int g = __gcd(abs(delta.x), abs(delta.y));
            delta.x /= g;
            delta.y /= g;
            pair<int, int> p_delta = {delta.x, delta.y};

            if (line_index[i].count(p_delta)) {
                lines[line_index[i][p_delta]].push_back(points[j].index);
            } else {
                line_index[i][p_delta] = lines.size();
                lines.push_back({points[i].index, points[j].index});
            }

            line_index[j][p_delta] = line_index[i][p_delta];
        }

    sort(points.begin(), points.end(), [&](const point &a, const point &b) { return a.index < b.index; });
    L = lines.size();

    for (vector<int> &line : lines) {
        sort(line.begin(), line.end());
        line.erase(unique(line.begin(), line.end()), line.end());
    }

    line_count.assign(N, 0);

    for (vector<int> &line : lines)
        for (int x : line)
            line_count[x]++;
}

void generate_transition_matrix() {
    vector<vector<double>> t(N, vector<double>(N, 0));

    for (vector<int> &line : lines)
        for (int x : line)
            for (int y : line)
                t[x][y] += 1.0 / (line_count[x] * line.size());

    transition = {t};
}

vector<double> get_success(int target, int steps) {
    steps = min(steps, 32);

    while (steps >= 1 << transition.size())
        transition.push_back(transition.back() * transition.back());

    float_column_vector column(N);
    column[target] = 1;

    for (int p = 0; 1 << p <= steps; p++)
        if (steps & 1 << p)
            column = transition[p] * column;

    return column.values;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(12);
    cin >> N;
    points.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].index = i;
    }

    generate_lines();
    generate_transition_matrix();
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int t, m;
        cin >> t >> m;
        t--;
        vector<double> success = get_success(t, m - 1);
        double answer = 0;

        for (vector<int> &line : lines) {
            double sum = 0;

            for (int x : line)
                sum += success[x];

            answer = max(answer, sum / line.size());
        }

        cout << answer << '\n';
    }
}