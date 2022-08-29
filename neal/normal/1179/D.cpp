#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
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
    long long x, y;

    point() : x(0), y(0) {}

    point(long long _x, long long _y) : x(_x), y(_y) {}
};

// dp_hull enables you to do the following two operations in amortized O(log n) time:
// 1. Insert a pair (a_i, b_i) into the structure
// 2. For any value of x, query the maximum value of a_i * x + b_i
// All values a_i, b_i, and x can be positive or negative.
struct dp_hull {
    struct segment {
        point p;
        mutable const point *next_p;

        segment(point _p = {0, 0}) : p(_p) {
            next_p = &p;
        }

        bool operator<(const point &other) const {
            return other.x * (next_p->x - p.x) > p.y - next_p->y;
        }

        bool operator<(const segment &other) const {
            return make_pair(p.x, p.y) < make_pair(other.p.x, other.p.y);
        }
    };

    set<segment, less<>> segments;

    int size() const {
        return segments.size();
    }

    set<segment, less<>>::iterator prev(set<segment, less<>>::iterator it) const {
        return it == segments.begin() ? it : --it;
    }

    set<segment, less<>>::iterator next(set<segment, less<>>::iterator it) const {
        return it == segments.end() ? it : ++it;
    }

    static long long floor_div(long long a, long long b) {
        return a / b - ((a ^ b) < 0 && a % b != 0);
    }

    static bool bad_middle(const point &a, const point &b, const point &c) {
        // This checks whether the x-value where b beats a comes after the x-value where c beats b. It's fine to round
        // down here if we will only query integer x-values. (Note: plain C++ division rounds toward zero)
        return floor_div(a.y - b.y, b.x - a.x) >= floor_div(b.y - c.y, c.x - b.x);
    }

    bool bad(set<segment, less<>>::iterator it) const {
        return it != segments.begin() && next(it) != segments.end() && bad_middle(prev(it)->p, it->p, next(it)->p);
    }

    void insert(const point &p) {
        auto next_it = segments.lower_bound(segment(p));

        if (next_it != segments.end() && p.x == next_it->p.x)
            return;

        if (next_it != segments.begin()) {
            auto prev_it = prev(next_it);

            if (p.x == prev_it->p.x)
                segments.erase(prev_it);
            else if (next_it != segments.end() && bad_middle(prev_it->p, p, next_it->p))
                return;
        }

        auto it = segments.insert(next_it, segment(p));

        while (bad(prev(it)))
            segments.erase(prev(it));

        while (bad(next(it)))
            segments.erase(next(it));

        if (it != segments.begin())
            prev(it)->next_p = &it->p;

        it->next_p = next(it) != segments.end() ? &next(it)->p : &it->p;
    }

    void insert(long long a, long long b) {
        insert(point(a, b));
    }

    // Queries the maximum value of ax + b.
    long long query(long long x) const {
        assert(size() > 0);
        auto it = segments.lower_bound(point(x, 1));
        return it->p.x * x + it->p.y;
    }
};


const long long LL_INF = (long long) 2e18 + 5;

long long N;
vector<vector<int>> adj;
vector<long long> subtree_size;
vector<long long> down_value;
long long best = LL_INF;

void erase_edge(int from, int to) {
    for (int &neighbor : adj[from])
        if (neighbor == to) {
            swap(neighbor, adj[from].back());
            adj[from].pop_back();
            return;
        }

    assert(false);
}

long long square(long long x) {
    return x * x;
}

void first_dfs(int node, int parent) {
    if (parent >= 0)
        erase_edge(node, parent);

    subtree_size[node] = 1;

    for (int child : adj[node]) {
        first_dfs(child, node);
        subtree_size[node] += subtree_size[child];
    }

    down_value[node] = square(subtree_size[node]);

    for (int child : adj[node])
        down_value[node] = min(down_value[node], square(subtree_size[node] - subtree_size[child]) + down_value[child]);
}

void second_dfs(int node) {
    for (int child : adj[node]) {
        second_dfs(child);
        long long option = down_value[child] + square(N - subtree_size[child]);
        best = min(best, option);
    }

    dp_hull hull;

    for (int child : adj[node]) {
        if (hull.size() > 0) {
            long long x = subtree_size[child];
            long long add = square(x) + N * N + down_value[child];
            best = min(best, -hull.query(x) + add);
        }

        long long a = 2 * (subtree_size[child] - N);
        long long b = -2 * N * subtree_size[child] + square(subtree_size[child]) + down_value[child];
        hull.insert(-a, -b);
    }
}

int main() {
    IO::read_int(N);
    adj.assign(N, {});

    if (N == 1) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        IO::read_int(u, v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    subtree_size.assign(N, LL_INF);
    down_value.assign(N, LL_INF);
    first_dfs(0, -1);
    second_dfs(0);
    assert(best % 2 == N % 2);
    cout << N * (N - 1) / 2 + (N * N - best) / 2 << '\n';
}