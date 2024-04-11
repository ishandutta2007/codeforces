#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T_weight>
struct Dijkstra {
    const T_weight W_INF = numeric_limits<T_weight>::max() / 2;

    struct edge {
        int node = -1;
        T_weight weight = 0;

        edge() {}

        edge(int _node, T_weight _weight) : node(_node), weight(_weight) {}
    };

    struct state {
        T_weight dist;
        int node;

        state() {}

        state(T_weight _dist, int _node) : dist(_dist), node(_node) {}

        bool operator<(const state &other) const {
            return dist > other.dist;
        }
    };

    int n;
    vector<vector<edge>> adj;
    vector<T_weight> dist;
    vector<int> parent;

    Dijkstra(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
    }

    void add_directional_edge(int a, int b, T_weight weight) {
        adj[a].emplace_back(b, weight);
    }

    void add_bidirectional_edge(int a, int b, T_weight weight) {
        add_directional_edge(a, b, weight);
        add_directional_edge(b, a, weight);
    }

    void dijkstra_check(priority_queue<state> &pq, int node, int from, T_weight new_dist) {
        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            parent[node] = from;
            pq.emplace(new_dist, node);
        }
    }

    void dijkstra(const vector<pair<int, T_weight>> &source) {
        if (n == 0) return;
        dist.assign(n, W_INF);
        parent.assign(n, -1);
        priority_queue<state> pq;

        for (const auto &pr : source)
            dijkstra_check(pq, pr.first, -1, pr.second);

        while (!pq.empty()) {
            state top = pq.top();
            pq.pop();

            if (top.dist > dist[top.node])
                continue;

            for (edge &e : adj[top.node])
                dijkstra_check(pq, e.node, top.node, top.dist + e.weight);
        }
    }
};


// TODO: set this to false if it's unnecessary and the time limit might be tight.
// CHECK_OVERFLOW64 = true can run up to 2 times slower (particularly on CF).
const bool CHECK_OVERFLOW64 = true;

struct point {
    int64_t x, y;

    point() : x(0), y(0) {}

    point(int64_t _x, int64_t _y) : x(_x), y(_y) {}

    point operator-(const point &other) const {
        return point(x - other.x, y - other.y);
    }
};

int cross_sign(const point &a, const point &b) {
    if (CHECK_OVERFLOW64) {
        long double double_value = (long double) a.x * b.y - (long double) b.x * a.y;

        if (abs(double_value) > 1e18)
            return double_value > 0 ? +1 : -1;
    }

    uint64_t uint64_value = (uint64_t) a.x * b.y - (uint64_t) b.x * a.y;
    int64_t actual = int64_t(uint64_value);
    return (actual > 0) - (actual < 0);
}

bool left_turn(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) > 0;
}

const int64_t INF64 = int64_t(2e18) + 5;

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
        prev_x = -INF64;
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

    void insert(int64_t a, int64_t b) {
        insert(point(a, b));
    }

    int64_t prev_x = -INF64, prev_y = 1;

    // Queries the maximum value of ax + by.
    int64_t query(int64_t x, int64_t y = 1) {
        assert(size() > 0);
        assert(y > 0);
        assert(prev_x == -INF64 || x * prev_y >= prev_x * y);
        prev_x = x; prev_y = y;

        while (size() >= 2 && (points[front + 1].x - points[front].x) * x + (points[front + 1].y - points[front].y) * y >= 0)
            front++;

        return points[front].x * x + points[front].y * y;
    }
};


template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, K;
    cin >> N >> M >> K;
    Dijkstra<int64_t> dijkstra(N);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        dijkstra.add_bidirectional_edge(u, v, w);
    }

    vector<int64_t> shortest(N, INF64);
    shortest[0] = 0;

    vector<int64_t> best = shortest;

    auto update_dijkstra = [&]() -> void {
        vector<pair<int, int64_t>> source(N);

        for (int i = 0; i < N; i++)
            source[i] = {i, shortest[i]};

        dijkstra.dijkstra(source);

        for (int i = 0; i < N; i++) {
            shortest[i] = dijkstra.dist[i];
            best[i] = min(best[i], shortest[i]);
        }
    };

    update_dijkstra();

    for (int k = 0; k < K; k++) {
        monotonic_dp_hull hull;

        for (int u = 0; u < N; u++)
            if (shortest[u] < INF64 / 2)
                hull.insert(2 * u, -(shortest[u] + int64_t(u) * u));

        for (int v = 0; v < N; v++) {
            shortest[v] = -hull.query(v) + int64_t(v) * v;
            shortest[v] = min(shortest[v], INF64);
        }

        update_dijkstra();
    }

    output_vector(best);
}