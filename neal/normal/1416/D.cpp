#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
#include <iostream>
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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x) {
        return -data[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);

        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};

struct segment {
    int maximum;

    segment(int _maximum = 0) : maximum(_maximum) {}

    void join(const segment &other) {
        maximum = max(maximum, other.maximum);
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

int right_half[32];

struct basic_seg_tree {
    static const bool POWER_OF_TWO_MODE = false;

    int tree_n = 0;
    vector<segment> tree;

    basic_seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        if (POWER_OF_TWO_MODE) {
            tree_n = 1;

            while (tree_n < n)
                tree_n *= 2;
        } else {
            tree_n = n;
        }

        tree.assign(2 * tree_n, segment());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) const {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;
        int r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                answer.join(tree[a++]);

            if (b & 1)
                right_half[r_size++] = --b;
        }

        for (int i = r_size - 1; i >= 0; i--)
            answer.join(tree[right_half[i]]);

        return answer;
    }

    segment query_single(int index) const {
        assert(0 <= index && index < tree_n);
        return tree[tree_n + index];
    }

    void join_up(int position) {
        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    void update(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position] = seg;
        join_up(position);
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> P(N);
    vector<int> where(N + 1, -1);

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        where[P[i]] = i;
    }

    vector<array<int, 2>> edges(M);

    for (auto &e : edges) {
        cin >> e[0] >> e[1];
        e[0]--; e[1]--;
    }

    vector<bool> deleted(M, false);
    vector<pair<int, int>> queries(Q);

    for (int q = 0; q < Q; q++) {
        int type, x;
        cin >> type >> x;
        x--;
        queries[q] = {type, x};

        if (type == 2)
            deleted[x] = true;
    }

    union_find UF(N);
    vector<int> tree_root(N);

    for (int i = 0; i < N; i++)
        tree_root[i] = i;

    vector<int> parent(N + M, -1);
    int V = N;

    auto add_edge = [&](int a, int b) {
        a = UF.find(a);
        b = UF.find(b);

        if (a == b) {
            parent[tree_root[a]] = V;
            tree_root[a] = V;
            V++;
        } else {
            UF.unite(a, b);
            parent[tree_root[a]] = parent[tree_root[b]] = V;
            tree_root[a] = tree_root[b] = V;
            V++;
        }
    };

    for (int i = 0; i < M; i++)
        if (!deleted[i])
            add_edge(edges[i][0], edges[i][1]);

    vector<int> query_node(Q, -1);

    for (int q = Q - 1; q >= 0; q--)
        if (queries[q].first == 1)
            query_node[q] = tree_root[UF.find(queries[q].second)];
        else
            add_edge(edges[queries[q].second][0], edges[queries[q].second][1]);

    assert(V == int(parent.size()));
    vector<vector<int>> children(V);

    for (int i = 0; i < V; i++)
        if (parent[i] >= 0)
            children[parent[i]].push_back(i);

    vector<int> leaf_start(V);
    vector<int> leaf_end(V);
    int leaf_index = 0;

    auto dfs = y_combinator([&](auto self, int node) -> void {
        leaf_start[node] = leaf_index;

        for (int child : children[node])
            self(child);

        leaf_index += node < N;
        leaf_end[node] = leaf_index;
    });

    for (int i = 0; i < V; i++)
        if (parent[i] < 0)
            dfs(i);

    basic_seg_tree tree(N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++)
        initial[leaf_start[i]] = segment(P[i]);

    tree.build(initial);

    for (int q = 0; q < Q; q++)
        if (queries[q].first == 1) {
            int node = query_node[q];
            int big = tree.query(leaf_start[node], leaf_end[node]).maximum;
            cout << big << '\n';

            if (big > 0)
                tree.update(leaf_start[where[big]], segment(0));
        }
}