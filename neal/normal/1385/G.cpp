#include <algorithm>
#include <array>
#include <cassert>
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

struct bipartite_union_find {
    vector<int> parent;
    vector<int> size;
    vector<bool> bipartite;
    vector<bool> edge_parity;
    int components = 0;

    bipartite_union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        bipartite.assign(n + 1, true);
        edge_parity.assign(n + 1, false);
        components = n;

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        int root = find(parent[x]);
        edge_parity[x] = edge_parity[x] ^ edge_parity[parent[x]];
        return parent[x] = root;
    }

    // Returns true if x and y are in the same component.
    bool query_component(int x, int y) {
        return find(x) == find(y);
    }

    // Returns the parity status between x and y. Requires that they are in the same component.
    bool query_parity(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        assert(x_root == y_root);
        return edge_parity[x] ^ edge_parity[y];
    }

    // Returns {union succeeded, edge consistent with bipartite conditions}.
    pair<bool, bool> unite(int x, int y, bool different = true) {
        int x_root = find(x);
        int y_root = find(y);

        if (x_root == y_root) {
            bool consistent = !(edge_parity[x] ^ edge_parity[y] ^ different);

            if (!consistent)
                bipartite[x_root] = false;

            return {false, consistent};
        }

        bool needed_parity = edge_parity[x] ^ edge_parity[y] ^ different;
        x = x_root;
        y = y_root;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        bipartite[x] = bipartite[x] && bipartite[y];
        edge_parity[y] = needed_parity;
        components--;
        return {true, true};
    }

    // Add an assertion that x and y are different; i.e., a normal edge.
    pair<bool, bool> add_different_edge(int x, int y) {
        return unite(x, y, true);
    }

    // Add an assertion that x and y are the same.
    pair<bool, bool> add_same_edge(int x, int y) {
        return unite(x, y, false);
    }
};

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int N;
vector<int> A[2];

void run_case() {
    cin >> N;
    vector<int> freq(N, 0);

    for (int row = 0; row < 2; row++) {
        A[row].resize(N);

        for (auto &a : A[row]) {
            cin >> a;
            a--;
            freq[a]++;
        }
    }

    for (int a = 0; a < N; a++)
        if (freq[a] != 2) {
            cout << -1 << '\n';
            return;
        }

    vector<array<pair<int, int>, 2>> locations(N, {make_pair(-1, -1), make_pair(-1, -1)});

    for (int row = 0; row < 2; row++)
        for (int i = 0; i < N; i++)
            for (int x = 0; x < 2; x++)
                if (locations[A[row][i]][x].first < 0) {
                    locations[A[row][i]][x] = {i, row};
                    break;
                }

    bool valid = true;
    bipartite_union_find UF(N);

    for (int a = 0; a < N; a++)
        if (locations[a][0].first != locations[a][1].first) {
            auto result = UF.unite(locations[a][0].first, locations[a][1].first, locations[a][0].second == locations[a][1].second);
            valid = valid && result.second;
        }

    if (!valid) {
        cout << -1 << '\n';
        return;
    }

    vector<array<vector<int>, 2>> components(N);

    for (int i = 0; i < N; i++) {
        int root = UF.find(i);
        bool parity = UF.query_parity(i, root);
        components[root][parity].push_back(i);
    }

    vector<int> columns;

    for (int i = 0; i < N; i++)
        if (UF.find(i) == i) {
            int smaller = components[i][0].size() > components[i][1].size();
            columns.insert(columns.end(), components[i][smaller].begin(), components[i][smaller].end());
        }

    cout << columns.size() << '\n';
    output_vector(columns, true);
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