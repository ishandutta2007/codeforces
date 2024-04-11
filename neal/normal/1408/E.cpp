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

template<typename T_edge>
struct kruskal {
    struct edge {
        int a, b;
        T_edge weight;
        int index = -1;
        bool in_tree = false;

        edge() {}

        edge(int _a, int _b, T_edge _weight, int _index = -1) : a(_a), b(_b), weight(_weight), index(_index) {}

        bool operator<(const edge &other) const {
            return weight < other.weight;
        }
    };

    union_find UF;
    vector<edge> edges;
    vector<bool> original_in_tree;

    kruskal(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        UF.init(n);
        edges = {};
    }

    void add_edge(int a, int b, T_edge weight) {
        edges.emplace_back(a, b, weight, edges.size());
        original_in_tree.push_back(false);
    }

    template<typename T_sum>
    T_sum solve() {
        sort(edges.begin(), edges.end());
        T_sum total = 0;

        for (edge &e : edges)
            if (UF.unite(e.a, e.b)) {
                total += e.weight;
                e.in_tree = true;
                original_in_tree[e.index] = true;
            }

        return total;
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int M, N;
    cin >> M >> N;
    vector<int> A(M), B(N);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    kruskal<int64_t> mst(N + M);
    int64_t total = 0;

    for (int m = 0; m < M; m++) {
        int s;
        cin >> s;

        for (int i = 0; i < s; i++) {
            int x;
            cin >> x;
            x--;
            int64_t cost = A[m] + B[x];
            total += cost;
            mst.add_edge(x, N + m, -cost);
        }
    }

    cout << total + mst.solve<int64_t>() << '\n';
}