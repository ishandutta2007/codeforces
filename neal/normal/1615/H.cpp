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

// Warning: when choosing flow_t, make sure it can handle the sum of flows, not just individual flows.
template<typename flow_t>
struct PushRelabel {
    struct Edge {
        int dest, back;
        flow_t f, c;
    };
    vector<vector<Edge>> g;
    vector<flow_t> ec;
    vector<Edge*> cur;
    vector<vector<int>> hs;
    vector<int> H;
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

    void addEdge(int s, int t, flow_t cap, flow_t rcap=0) {
        if (s == t) return;
        g[s].push_back({t, int(g[t].size()), 0, cap});
        g[t].push_back({s, int(g[s].size())-1, 0, rcap});
    }

    void addFlow(Edge& e, flow_t f) {
        Edge &back = g[e.dest][e.back];
        if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
        e.f += f; e.c -= f; ec[e.dest] += f;
        back.f -= f; back.c += f; ec[back.dest] -= f;
    }
    flow_t calc(int s, int t) {
        int v = int(g.size()); H[s] = v; ec[t] = 1;
        vector<int> co(2*v); co[0] = v-1;
        for (int i = 0; i < v; i++) cur[i] = g[i].data();
        for (Edge& e : g[s]) addFlow(e, e.c);

        for (int hi = 0;;) {
            while (hs[hi].empty()) if (!hi--) return -ec[s];
            int u = hs[hi].back(); hs[hi].pop_back();
            while (ec[u] > 0)  // discharge u
                if (cur[u] == g[u].data() + g[u].size()) {
                    H[u] = 1e9;
                    for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
                        H[u] = H[e.dest]+1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        for (int i = 0; i < v; i++) if (hi < H[i] && H[i] < v)
                            --co[H[i]], H[i] = v + 1;
                    hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
                    addFlow(*cur[u], min(ec[u], cur[u]->c));
                else ++cur[u];
        }
    }
    bool leftOfMinCut(int a) { return H[a] >= int(g.size()); }
};

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


const int INF = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int64_t> sorted = A;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int S = int(sorted.size());
    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    int V = N + 2;
    int source = V - 2, sink = V - 1;
    PushRelabel<int> base_graph(V);

    for (int i = 0; i < N; i++)
        for (int j : adj[i])
            base_graph.addEdge(j, i, INF);

    vector<int64_t> B(N, sorted.front());
    int64_t total = 0;

    for (int s = 0; s < S - 1; s++) {
        int64_t lower = sorted[s];
        int64_t upper = sorted[s + 1];
        PushRelabel<int> graph = base_graph;

        for (int i = 0; i < N; i++)
            if (B[i] >= lower) {
                if (A[i] <= lower) graph.addEdge(source, i, 1);
                if (A[i] >= upper) graph.addEdge(i, sink, 1);
            } else if (A[i] >= upper) {
                total += upper - lower;
            }

        int flow = graph.calc(source, sink);
        total += (upper - lower) * flow;

        for (int i = 0; i < N; i++)
            if (B[i] >= lower && !graph.leftOfMinCut(i))
                B[i] = max(B[i], upper);
    }

    output_vector(B);
    int64_t diff = 0;

    for (int i = 0; i < N; i++)
        diff += abs(A[i] - B[i]);

    cerr << diff << ' ' << total << endl;
    assert(total == diff);
}