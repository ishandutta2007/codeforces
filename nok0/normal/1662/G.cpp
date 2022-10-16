#line 2 "/home/nok0/documents/programming/library/template/header.hpp"
#include <bits/stdc++.h>
#line 3 "/home/nok0/documents/programming/library/graph/graph.hpp"

#pragma region graph

template<class cost_type = long long>
class graph {
public:
    struct edge {
    public:
        int from, to;
        cost_type cost;
        int id;
        edge() = default;
        edge(int from_, int to_, cost_type cost_ = 1, int id_ = -1) : from(from_), to(to_), cost(cost_), id(id_) {}
        bool operator<(const edge &a) const { return cost < a.cost; }
        bool operator>(const edge &a) const { return cost > a.cost; }
        friend std::ostream &operator<<(std::ostream &s, const edge &a) {
            s << '(' << a.from << " -> " << a.to << "), cost: " << a.cost << ", id: " << a.id;
            return s;
        }
    };

private:
    std::vector<std::vector<edge>> edges;
    int next_edge_id = 0;

public:
    inline const std::vector<edge> &operator[](int k) const { return edges[k]; }
    inline std::vector<edge> &operator[](int k) { return edges[k]; }

    int size() const { return int(edges.size()); }
    void resize(const int n) { edges.resize(n); }
    int edge_count() const { return next_edge_id; }

    friend std::ostream &operator<<(std::ostream &s, const graph<cost_type> &g) {
        for (const auto &adj : g.edges)
            for (const auto &ed : adj) s << ed << '\n';
        return s;
    }

    graph() = default;
    graph(int n) : edges(n) {}
    graph(int n, int e, bool weight = 0, bool directed = 0, int idx = 1) : edges(n) { input(e, weight, directed, idx); }
    const cost_type INF = std::numeric_limits<cost_type>::max() / 3;

    void input(int e = -1, bool weight = false, bool directed = false, int idx = 1) {
        if (e == -1) e = size() - 1;
        while (e--) {
            int u, v;
            std::cin >> u >> v;
            cost_type cost = 1;
            if (weight) std::cin >> cost;
            add_edge(u, v, cost, directed, idx);
        }
    }

    inline int add_edge(int u, int v, cost_type cost = 1, bool directed = false, int idx = 0) {
        u -= idx, v -= idx;
        edges[u].emplace_back(u, v, cost, next_edge_id);
        if (!directed && u != v) edges[v].emplace_back(v, u, cost, next_edge_id);
        return next_edge_id++;
    }

    // (V+E)
    std::vector<cost_type> bfs(int s) {
        std::vector<cost_type> dist(size(), INF);
        std::queue<int> que;
        dist[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto &e : edges[v]) {
                if (dist[e.to] != INF) continue;
                dist[e.to] = dist[v] + e.cost;
                que.push(e.to);
            }
        }
        return dist;
    }

    // (V+E)
    // constraint: cost of each edge is zero or x (>= 0)
    std::vector<cost_type> zero_one_bfs(int s) {
        std::vector<cost_type> dist(size(), INF);
        std::deque<int> deq;
        dist[s] = 0;
        deq.push_back(s);
        while (!deq.empty()) {
            int v = deq.front();
            deq.pop_front();
            for (auto &e : edges[v]) {
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    e.cost ? deq.push_back(e.to) : deq.push_front(e.to);
                }
            }
        }
        return dist;
    }

    // ((E+V) lg E)
    // unreachable: INF
    std::vector<cost_type> dijkstra(int s) {  // verified
        std::vector<cost_type> dist(size(), INF);
        const auto compare = [](const std::pair<cost_type, int> &a, const std::pair<cost_type, int> &b) {
            return a.first > b.first;
        };
        std::priority_queue<std::pair<cost_type, int>, std::vector<std::pair<cost_type, int>>, decltype(compare)> que {compare};
        dist[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            std::pair<cost_type, int> p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (auto &e : edges[v]) {
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    que.emplace(dist[e.to], e.to);
                }
            }
        }
        return dist;
    }

    // (VE)
    // unreachable: INF
    // reachable via negative cycle: -INF
    std::vector<cost_type> bellman_ford(int s) {
        int n = size();
        std::vector<cost_type> res(n, INF);
        res[s] = 0;
        for (int loop = 0; loop < n - 1; loop++) {
            for (int v = 0; v < n; v++) {
                if (res[v] == INF) continue;
                for (auto &e : edges[v]) {
                    res[e.to] = std::min(res[e.to], res[v] + e.cost);
                }
            }
        }
        std::queue<int> que;
        std::vector<int> chk(n);
        for (int v = 0; v < n; v++) {
            if (res[v] == INF) continue;
            for (auto &e : edges[v]) {
                if (res[e.to] > res[v] + e.cost and !chk[e.to]) {
                    que.push(e.to);
                    chk[e.to] = 1;
                }
            }
        }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (auto &e : edges[now]) {
                if (!chk[e.to]) {
                    chk[e.to] = 1;
                    que.push(e.to);
                }
            }
        }
        for (int i = 0; i < n; i++)
            if (chk[i]) res[i] = -INF;
        return res;
    }

    // (V^3)
    std::vector<std::vector<cost_type>> warshall_floyd() {
        int n = size();
        std::vector<std::vector<cost_type>> dist(n, std::vector<cost_type>(n, INF));
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (int i = 0; i < n; i++)
            for (auto &e : edges[i]) dist[i][e.to] = std::min(dist[i][e.to], e.cost);
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < n; j++) {
                    if (dist[k][j] == INF) continue;
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        return dist;
    }

    // (V) (using DFS)
    // if a cycle exists, return {}
    std::vector<int> topological_sort() {
        std::vector<int> res;
        int n = size();
        std::vector<int> used(n, 0);
        bool not_DAG = false;
        auto dfs = [&](auto self, int k) -> void {
            if (not_DAG) return;
            if (used[k]) {
                if (used[k] == 1) not_DAG = true;
                return;
            }
            used[k] = 1;
            for (auto &e : edges[k]) self(self, e.to);
            used[k] = 2;
            res.push_back(k);
        };
        for (int i = 0; i < n; i++) dfs(dfs, i);
        if (not_DAG) return std::vector<int> {};
        std::reverse(res.begin(), res.end());
        return res;
    }

    bool is_dag() { return !topological_sort().empty(); }

    // (V)
    // array of the distance to the most distant vertex
    // constraint: the graph is a tree
    std::vector<cost_type> height() {
        auto vec1 = bfs(0);
        int v1 = -1, v2 = -1;
        cost_type dia = -1;
        for (int i = 0; i < int(size()); i++)
            if (dia < vec1[i]) dia = vec1[i], v1 = i;
        vec1 = bfs(v1);
        dia = -1;
        for (int i = 0; i < int(size()); i++)
            if (dia < vec1[i]) dia = vec1[i], v2 = i;
        auto vec2 = bfs(v2);
        for (int i = 0; i < int(size()); i++) {
            if (vec1[i] < vec2[i]) vec1[i] = vec2[i];
        }
        return vec1;
    }

    // O(V+E)
    // vector<(int)(0 or 1)>
    // if it is not bipartite, return {}
    std::vector<int> bipartite_grouping() {
        std::vector<int> colors(size(), -1);
        auto dfs = [&](auto self, int now, int col) -> bool {
            colors[now] = col;
            for (auto &e : edges[now]) {
                if (col == colors[e.to]) return false;
                if (colors[e.to] == -1 and !self(self, e.to, !col)) return false;
            }
            return true;
        };
        for (int i = 0; i < int(size()); i++)
            if (!colors[i] and !dfs(dfs, i, 0)) return std::vector<int> {};
        return colors;
    }

    bool is_bipartite() { return !bipartite_grouping().empty(); }

    // (V+E)
    // (v1, v2, diameter)
    std::tuple<int, int, cost_type> diameter() {
        std::vector<cost_type> dist = bfs(0);
        auto it = std::max_element(dist.begin(), dist.end());
        const int v = it - dist.begin();
        dist = bfs(v);
        it = std::max_element(dist.begin(), dist.end());
        return std::make_tuple(v, int(it - dist.begin()), *it);
    }

    // (ElgE)
    cost_type prim() {
        cost_type res = 0;
        std::priority_queue<edge, std::vector<edge>, std::greater<edge>> que;
        for (auto &e : edges[0]) que.push(e);
        std::vector<int> chk(size());
        chk[0] = 1;
        int cnt = 1;
        while (cnt < size()) {
            auto e = que.top();
            que.pop();
            if (chk[e.to]) continue;
            cnt++;
            res += e.cost;
            chk[e.to] = 1;
            for (auto &e2 : edges[e.to]) que.push(e2);
        }
        return res;
    }

    // (ElgE)
    cost_type kruskal() {
        std::vector<std::tuple<int, int, cost_type>> edges;
        for (int i = 0; i < int(size()); i++)
            for (auto &e : edges[i]) edges.emplace_back(i, e.to, e.cost);
        std::sort(edges.begin(), edges.end(), [](const std::tuple<int, int, cost_type> &a, const std::tuple<int, int, cost_type> &b) {
            return std::get<2>(a) < std::get<2>(b);
        });
        std::vector<int> uf_data(size(), -1);
        auto root = [&uf_data](auto self, int x) -> int {
            if (uf_data[x] < 0) return x;
            return uf_data[x] = self(self, uf_data[x]);
        };
        auto unite = [&uf_data, &root](int u, int v) -> bool {
            u = root(root, u), v = root(root, v);
            if (u == v) return false;
            if (uf_data[u] > uf_data[v]) std::swap(u, v);
            uf_data[u] += uf_data[v];
            uf_data[v] = u;
            return true;
        };
        cost_type ret = 0;
        for (auto &e : edges)
            if (unite(std::get<0>(e), std::get<1>(e))) ret += std::get<2>(e);
        return ret;
    }

    // O(V)
    std::vector<int> centroid() {
        int n = size();
        std::vector<int> centroid, sz(n);
        auto dfs = [&](auto self, int now, int per) -> void {
            sz[now] = 1;
            bool is_centroid = true;
            for (auto &e : edges[now]) {
                if (e.to != per) {
                    self(self, e.to, now);
                    sz[now] += sz[e.to];
                    if (sz[e.to] > n / 2) is_centroid = false;
                }
            }
            if (n - sz[now] > n / 2) is_centroid = false;
            if (is_centroid) centroid.push_back(now);
        };
        dfs(dfs, 0, -1);
        return centroid;
    }

    // O(V+E)
    // bridge: (s, t)  (s < t);
    std::pair<std::vector<std::pair<int, int>>, std::vector<int>> bridges_and_articulations() {  // verified
        std::vector<int> order(size(), -1), low(size()), articulation;
        int order_next = 0;
        std::vector<std::pair<int, int>> bridge;
        auto dfs = [&](auto self, int now, int par = -1) -> void {
            low[now] = order[now] = order_next++;
            bool is_articulation = false;
            int cnt = 0;
            for (auto &ed : edges[now]) {
                int &nxt = ed.to;
                if (nxt == par) continue;
                if (order[nxt] == -1) {
                    cnt++;
                    self(self, nxt, now);
                    if (order[now] < low[nxt]) bridge.push_back(std::minmax(now, nxt));
                    if (order[now] <= low[nxt]) is_articulation = true;
                    low[now] = std::min(low[now], low[nxt]);
                } else if (order[now] > order[nxt]) {
                    low[now] = std::min(low[now], order[nxt]);
                }
            }
            if (par == -1 and cnt < 2) is_articulation = false;
            if (is_articulation) articulation.push_back(now);
            return;
        };
        for (int i = 0; i < (int)size(); i++)
            if (order[i] == -1) dfs(dfs, i);
        return std::make_pair(bridge, articulation);
    }

    // (V+E)
    // directed graph from root to leaf
    graph root_to_leaf(int root = 0) {
        graph res(size());
        std::vector<int> chk(size(), 0);
        chk[root] = 1;
        auto dfs = [&](auto self, int now) -> void {
            for (auto &e : edges[now]) {
                if (chk[e.to] == 1) continue;
                chk[e.to] = 1;
                res.add_edge(now, e.to, e.cost, 1, 0);
                self(self, e.to);
            }
        };
        dfs(dfs, root);
        return res;
    }

    // (V+E)
    // directed graph from leaf to root
    graph leaf_to_root(int root = 0) {
        graph res(size());
        std::vector<int> chk(size(), 0);
        chk[root] = 1;
        auto dfs = [&](auto self, int now) -> void {
            for (auto &e : edges[now]) {
                if (chk[e.to] == 1) continue;
                chk[e.to] = 1;
                res.add_edge(e.to, now, e.cost, 1, 0);
                self(self, e.to);
            }
        };
        dfs(dfs, root);
        return res;
    }

    // cost_type Chu_Liu_Edmonds(int root = 0) {}
};
#pragma endregion
#line 3 "/home/nok0/documents/programming/library/template/def_name.hpp"

#define pb        push_back
#define eb        emplace_back
#define SZ(x)     ((int)(x).size())
#define all(x)    (x).begin(), (x).end()
#define rall(x)   (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template<class T = int>
using V = std::vector<T>;
template<class T = int>
using VV = std::vector<std::vector<T>>;
template<class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
#line 3 "/home/nok0/documents/programming/library/template/input.hpp"

template<class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}
template<class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
    for (T &i : v) is >> i;
    return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
    std::string s;
    is >> s;
    __int128_t ret = 0;
    for (int i = 0; i < (int)s.length(); i++)
        if ('0' <= s[i] and s[i] <= '9')
            ret = 10 * ret + s[i] - '0';
    a = ret * (s[0] == '-' ? -1 : 1);
    return is;
}
namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template<class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template<class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template<class Head, class... Tail>
void INPUT(Head &head, Tail &...tail) {
    scan(head);
    INPUT(tail...);
}
}  // namespace scanner
#define VEC(type, name, size)     \
    std::vector<type> name(size); \
    scanner::INPUT(name)
#define VVEC(type, name, h, w)                                    \
    std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
    scanner::INPUT(name)
#define INT(...)     \
    int __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
    long long __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define STR(...)             \
    std::string __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define CHAR(...)     \
    char __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
    double __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
    long double __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#line 3 "/home/nok0/documents/programming/library/template/output.hpp"


template<class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
    os << p.first << " " << p.second;
    return os;
}
template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
    for (int i = 0; i < int(a.size()); ++i) {
        if (i) os << " ";
        os << a[i];
    }
    return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}
template<class T>
void print(const T a) { std::cout << a << '\n'; }
template<class Head, class... Tail>
void print(Head H, Tail... T) {
    std::cout << H << ' ';
    print(T...);
}
template<class T>
void printel(const T a) { std::cout << a << '\n'; }
template<class T>
void printel(const std::vector<T> &a) {
    for (const auto &v : a)
        std::cout << v << '\n';
}
template<class Head, class... Tail>
void printel(Head H, Tail... T) {
    std::cout << H << '\n';
    printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "NO\n"; }
#line 2 "/home/nok0/documents/programming/library/template/rep.hpp"

#define foa(v, a)                   for (auto &v : a)
#define repname(a, b, c, d, e, ...) e
#define rep(...)                    repname(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define rep0(x)                     for (int rep_counter = 0; rep_counter < (x); ++rep_counter)
#define rep1(i, x)                  for (int i = 0; i < (x); ++i)
#define rep2(i, l, r)               for (int i = (l); i < (r); ++i)
#define rep3(i, l, r, c)            for (int i = (l); i < (r); i += (c))

#define repsname(a, b, c, ...) c
#define reps(...)              repsname(__VA_ARGS__, reps1, reps0)(__VA_ARGS__)
#define reps0(x)               for (int reps_counter = 1; reps_counter <= (x); ++reps_counter)
#define reps1(i, x)            for (int i = 1; i <= (x); ++i)

#define rrepname(a, b, c, ...) c
#define rrep(...)              rrepname(__VA_ARGS__, rrep1, rrep0)(__VA_ARGS__)
#define rrep0(x)               for (int rrep_counter = (x)-1; rrep_counter >= 0; --rrep_counter)
#define rrep1(i, x)            for (int i = (x)-1; i >= 0; --i)
#line 6 "/home/nok0/documents/programming/library/template/all"
using namespace std;
#line 3 "a.cpp"

int main() {
    INT(n);

    graph g(n);
    rep(i, 1, n) {
        INT(p);
        g.add_edge(p - 1, i);
    }

    auto cent = g.centroid()[0];
    auto h = g.root_to_leaf(cent);

    ll base_ans = n;

    V<> ws;
    for (auto e : h[cent]) {
        auto dfs = [&](auto dfs, int now, int dep) -> int {
            int ret = 1;
            base_ans += dep;
            for (auto nx : h[now]) {
                ret += dfs(dfs, nx.to, dep + 1);
            }
            return ret;
        };
        ws.push_back(dfs(dfs, e.to, 1));
    }

    vector<int> cnt(n + 1);

    foa(w, ws) cnt[w]++;

    vector<int> nw;

    reps(i, n) {
        if (!cnt[i]) continue;
        int d = 1;
        while (cnt[i] >= d) {
            cnt[i] -= d;
            nw.pb(i * d);
            d <<= 1;
        }
        if (cnt[i]) nw.pb(i * cnt[i]);
    }

    bitset<1000001> bs;
    bs[0] = 1;

    foa(w, nw) {
        bs = (bs | (bs << w));
    }

    ll ans = 0;

    reps(i, n - 1) {
        if (bs[i]) {
            ans = max(ans, ll(i) * (n - 1 - i));
        }
    }

    print(ans + base_ans);
}