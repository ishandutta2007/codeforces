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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


struct edge {
    int node, index;

    edge() {}

    edge(int _node, int _index) : node(_node), index(_index) {}
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<int> P(N);

    for (auto &p : P) {
        cin >> p;
        p--;
    }

    vector<array<int, 2>> swaps(M);
    vector<vector<edge>> adj(N);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].emplace_back(y, i);
        adj[y].emplace_back(x, i);
        swaps[i] = {x, y};
    }

    vector<int> cycle_size(N, -1);
    vector<int> cycle_index(N, -1);
    int c_index = 0;

    for (int i = 0; i < N; i++)
        if (cycle_index[i] < 0) {
            int x = i, cycle = 0;

            do {
                cycle_index[x] = c_index++;
                cycle++;
                x = P[x];
            } while (x != i);

            do {
                cycle_size[x] = cycle;
                x = P[x];
            } while (x != i);
        }

    for (int i = 0; i < N; i++)
        sort(adj[i].begin(), adj[i].end(), [&](edge a, edge b) -> bool {
            int a_index = (cycle_index[a.node] - cycle_index[i] + cycle_size[i]) % cycle_size[i];
            int b_index = (cycle_index[b.node] - cycle_index[i] + cycle_size[i]) % cycle_size[i];
            return a_index < b_index;
        });

    vector<int> adj_index(N, 0);
    vector<int> edge_counter(M, 0);
    vector<int> full_edges;
    vector<int> solution;

    auto increment = [&](int e) -> void {
        edge_counter[e]++;
        assert(edge_counter[e] <= 2);

        if (edge_counter[e] == 2)
            full_edges.push_back(e);
    };

    auto bump_up = [&](int x) -> void {
        adj_index[x]++;

        if (adj_index[x] < int(adj[x].size()))
            increment(adj[x][adj_index[x]].index);
    };

    auto process_edge = [&](int e) -> void {
        solution.push_back(e);
        int x = swaps[e][0];
        int y = swaps[e][1];
        bump_up(x);
        bump_up(y);
    };

    for (int i = 0; i < N; i++)
        if (!adj[i].empty())
            increment(adj[i][0].index);

    while (!full_edges.empty()) {
        int e = full_edges.back();
        full_edges.pop_back();
        process_edge(e);
    }

    output_vector(solution, true);
}