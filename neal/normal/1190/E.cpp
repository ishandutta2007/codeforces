#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
}


struct point {
    int x, y;
    double angle, dist;

    point() : x(0), y(0) {}

    point(int _x, int _y) : x(_x), y(_y) {}

    long long norm() const {
        return (long long) x * x + (long long) y * y;
    }

    bool operator<(const point &other) const {
        return angle < other.angle;
    }
};

const double PI = acos(-1.0);
const double DOUBLE_INF = 1e50;

const int BINARY_SEARCH = 24;

struct interval {
    double start, end;

    interval(double _start = 0, double _end = 0) : start(_start), end(_end) {}

    bool operator<(const interval &other) const {
        return start < other.start;
    }
};

int N, M;
vector<point> points;

bool possible(double radius) {
    static vector<interval> intervals;
    intervals.resize(2 * N);

    for (int i = 0; i < N; i++) {
        double angle = points[i].angle;
        double diff = acos(radius / points[i].dist);
        intervals[i] = interval(angle - diff, angle + diff);
    }

    sort(intervals.begin(), intervals.begin() + N);

    for (int i = 0; i < N; i++)
        intervals[N + i] = interval(intervals[i].start + 2 * PI, intervals[i].end + 2 * PI);

    // Set each interval's end to the minimum end of any interval whose start is >= its start.
    double lowest = DOUBLE_INF;

    for (int i = 2 * N - 1; i >= 0; i--) {
        lowest = min(lowest, intervals[i].end);
        intervals[i].end = lowest;
    }

    static vector<int> jump;
    jump.resize(2 * N + 1);
    jump[2 * N] = 2 * N;

    for (int i = 0, j = 0; i < N; i++) {
        while (j < 2 * N && intervals[j].start < intervals[i].end)
            j++;

        jump[i] = j;
    }

    for (int i = 0; i < N; i++)
        jump[N + i] = min(jump[i] + N, 2 * N);

    static vector<bool> seen;
    seen.assign(N, false);
    int position = 0;

    while (!seen[position]) {
        seen[position] = true;
        position = jump[position];

        if (position >= N)
            position -= N;
    }

    int original = position, count = 0;

    while (position < N + original && count < M) {
        position = jump[position];
        count++;
    }

    return position >= N + original;
}

int main() {
    cout << setprecision(16);

    IO::read_int(N, M);
    points.resize(N);
    double closest = DOUBLE_INF;

    for (point &p : points) {
        IO::read_int(p.x, p.y);

        if (p.x == 0 && p.y == 0) {
            cout << 0 << '\n';
            return 0;
        }

        p.angle = atan2(p.y, p.x);
        p.dist = sqrt(p.norm());
        closest = min(closest, p.dist);
    }

    sort(points.begin(), points.end());
    double low = 0, high = closest;

    if (possible(1))
        low = 1;
    else
        high = 1;

    for (int iter = 0; iter < BINARY_SEARCH; iter++) {
        double mid = high <= 1 ? (low + high) / 2 : sqrt(low * high);

        if (possible(mid))
            low = mid;
        else
            high = mid;
    }

    cout << low << '\n';
}