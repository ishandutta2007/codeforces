#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// Warning: it may not be possible to use this implementation for incremental flows; i.e., call flow, add edges, call flow again.
template <int MAXN, class T = int>
struct HLPP {
    const T T_INF = numeric_limits<T>::max();
    struct edge {
        int to, rev;
        T f;
    };
    int V;
    vector<edge> adj[MAXN];
    vector<int> lst[MAXN], gap[MAXN];
    T excess[MAXN];
    int height[MAXN], cnt[MAXN];
    int highest = 0, work = 0;
    HLPP(int _V = 0) : V(_V) {}
    void addEdge(int from, int to, T f, bool isDirected = true) {
        adj[from].push_back({to, int(adj[to].size()), f});
        adj[to].push_back({from, int(adj[from].size()) - 1, isDirected ? 0 : f});
    }
    void updHeight(int v, int nh) {
        work++;
        if (height[v] != MAXN)
            cnt[height[v]]--;
        height[v] = nh;
        if (nh == MAXN)
            return;
        cnt[nh]++, highest = nh;
        gap[nh].push_back(v);
        if (excess[v] > 0)
            lst[nh].push_back(v);
    }
    void globalRelabel(int t) {
        work = 0;
        fill(begin(height), begin(height) + V, MAXN);
        fill(begin(cnt), begin(cnt) + V, 0);
        for (int i = 0; i < highest; i++)
            lst[i].clear(), gap[i].clear();
        height[t] = 0;
        queue<int> q({t});
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto &e : adj[v])
                if (height[e.to] == MAXN && adj[e.to][e.rev].f > 0)
                    q.push(e.to), updHeight(e.to, height[v] + 1);
            highest = height[v];
        }
    }
    void push(int v, edge &e) {
        if (excess[e.to] == 0)
            lst[height[e.to]].push_back(e.to);
        T df = min(excess[v], e.f);
        e.f -= df, adj[e.to][e.rev].f += df;
        excess[v] -= df, excess[e.to] += df;
    }
    void discharge(int v) {
        int nh = MAXN;
        for (auto &e : adj[v])
            if (e.f > 0) {
                if (height[v] == height[e.to] + 1) {
                    push(v, e);
                    if (excess[v] <= 0)
                        return;
                } else {
                    nh = min(nh, height[e.to] + 1);
                }
            }
        if (height[v] != MAXN && cnt[height[v]] > 1) {
            updHeight(v, nh);
        } else {
            for (int i = height[v]; i <= highest; i++) {
                for (auto j : gap[i])
                    updHeight(j, MAXN);
                gap[i].clear();
            }
        }
    }
    T calc(int s, int t) {
        fill(begin(excess), begin(excess) + V, 0);
        excess[s] = T_INF, excess[t] = -T_INF;
        globalRelabel(t);
        for (auto &e : adj[s])
            push(s, e);
        for (; highest >= 0; highest--) {
            while (!lst[highest].empty()) {
                int v = lst[highest].back();
                lst[highest].pop_back();
                discharge(v);
                if (work > 4 * V)
                    globalRelabel(t);
            }
        }
        return excess[t] + T_INF;
    }
};


const int V_MAX = 40005;
const char BLACK = '#';

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<string> grid(N);

    for (string &row : grid)
        cin >> row;

    int V = N * M + 2;
    int source = V - 2, sink = V - 1;
    HLPP<V_MAX> graph(V);

    auto get_index = [&](int r, int c) {
        return r * M + c;
    };

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (grid[r][c] == BLACK) {
                int above = r > 0 && grid[r - 1][c] == BLACK ? get_index(r - 1, c) : source;
                graph.addEdge(above, get_index(r, c), 1);

                int right = c < M - 1 && grid[r][c + 1] == BLACK ? get_index(r, c + 1) : sink;
                graph.addEdge(get_index(r, c), right, 1);
            }

    cout << graph.calc(source, sink) << '\n';
}