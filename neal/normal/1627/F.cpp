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

    void dijkstra(const vector<int> &source) {
        if (n == 0) return;
        dist.assign(n, W_INF);
        parent.assign(n, -1);
        priority_queue<state> pq;

        for (int src : source)
            dijkstra_check(pq, src, -1, 0);

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

const int DIRS = 4;
const int DR[DIRS] = {-1,  0, +1,  0};
const int DC[DIRS] = { 0, +1,  0, -1};


const int INF = int(1e9) + 5;

void run_case() {
    int N, K;
    cin >> N >> K;
    assert(K % 2 == 0);
    int H = K / 2;
    int V = (K + 1) * (K + 1);

    auto encode = [&](int r, int c) -> int {
        return (K + 1) * r + c;
    };

    vector<array<int, 2>> edge(V);

    auto get_edge = [&](int index1, int index2) -> int & {
        if (index1 > index2)
            swap(index1, index2);

        return edge[index1][index2 - index1 == K + 1];
    };

    auto add_cost = [&](int r1, int c1, int r2, int c2) {
        for (int iter = 0; iter < 2; iter++) {
            int index1 = encode(r1, c1);
            int index2 = encode(r2, c2);
            get_edge(index1, index2)++;
            r1 = K - r1;
            c1 = K - c1;
            r2 = K - r2;
            c2 = K - c2;
        }
    };

    for (int i = 0; i < N; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;

        if (r1 + c1 > r2 + c2) {
            swap(r1, r2);
            swap(c1, c2);
        }

        r1++; c1++;
        add_cost(r1, c1, r2, c2);
    }

    auto valid = [&](int r, int c) -> bool {
        return 0 <= r && r <= K && 0 <= c && c <= K;
    };

    Dijkstra<int> dijkstra(V);

    for (int r = 0; r <= K; r++)
        for (int c = 0; c <= K; c++)
            for (int dir = 0; dir < DIRS; dir++) {
                int nr = r + DR[dir];
                int nc = c + DC[dir];

                if (valid(nr, nc)) {
                    int index = encode(r, c);
                    int nindex = encode(nr, nc);
                    dijkstra.add_directional_edge(index, nindex, get_edge(index, nindex));
                }
            }

    dijkstra.dijkstra({encode(H, H)});
    int best = INF;

    for (int r = 0; r <= K; r++)
        for (int c = 0; c <= K; c++)
            if (r == 0 || r == K || c == 0 || c == K)
                best = min(best, dijkstra.dist[encode(r, c)]);

    cout << N - best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}