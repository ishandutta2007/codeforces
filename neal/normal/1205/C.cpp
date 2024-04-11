#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct bipartite_union_find {
    vector<int> parent;
    vector<int> size;
    vector<bool> bipartite;
    vector<bool> edge_parity;
    int components = 0;

    bipartite_union_find(int n = 0) {
        if (n > 0)
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

    pair<bool, bool> add_different_edge(int x, int y) {
        return unite(x, y, true);
    }

    pair<bool, bool> add_same_edge(int x, int y) {
        return unite(x, y, false);
    }
};


int N;
bipartite_union_find UF;

int query(int r1, int c1, int r2, int c2) {
    cout << "? " << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
    int result;
    cin >> result;

    if (result < 0)
        exit(0);

    return result;
}

int convert(int r, int c) {
    return (r - 1) * N + (c - 1);
}

void output() {
    cout << "!" << '\n';

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++)
            cout << UF.query_parity(convert(r, c), convert(N, N));

        cout << '\n';
    }

    cout << flush;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    UF.init(N * N);
    UF.unite(convert(1, 1), convert(N, N), true);

    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++)
            if ((r + c) % 2 == 0 && r + c > 2 && r + c < 2 * N) {
                int prev_r = r - 2, prev_c = c;

                while (prev_r < 1) {
                    prev_r++;
                    prev_c--;
                }

                UF.unite(convert(prev_r, prev_c), convert(r, c), !query(prev_r, prev_c, r, c));
            }

    UF.unite(convert(2, 1), convert(2, 3), !query(2, 1, 2, 3));

    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++)
            if ((r + c) % 2 != 0 && r + c > 3) {
                int prev_r = r - 2, prev_c = c;

                while (prev_r < 1) {
                    prev_r++;
                    prev_c--;
                }

                UF.unite(convert(prev_r, prev_c), convert(r, c), !query(prev_r, prev_c, r, c));
            }

    bool finished = false;

    for (int r = 2; r <= N && !finished; r++)
        for (int c = 1; c < N && !finished; c++)
            if (UF.query_parity(convert(r, c), convert(r - 1, c + 1))) {
                int start_r = r - 1, start_c = max(c - 1, 1);
                int end_r = start_r + 1, end_c = start_c + 2;
                UF.unite(convert(start_r, start_c), convert(end_r, end_c), !query(start_r, start_c, end_r, end_c));
                finished = true;
                break;
            }

    if (finished) {
        output();
        return 0;
    }

    // All r + c diagonals are equal now.
    for (int r = 1; r < N && !finished; r++)
        for (int c = 1; c < N && !finished; c++) {
            bool first = UF.query_parity(convert(r, c), convert(r + 1, c + 1));

            if (r + 2 <= N) {
                bool second = UF.query_parity(convert(r + 1, c), convert(r + 2, c + 1));

                if (first == second) {
                    UF.unite(convert(r, c), convert(r + 2, c + 1), !query(r, c, r + 2, c + 1));
                    finished = true;
                    break;
                }
            }

            if (c + 2 <= N) {
                bool second = UF.query_parity(convert(r, c + 1), convert(r + 1, c + 2));

                if (first == second) {
                    UF.unite(convert(r, c), convert(r + 1, c + 2), !query(r, c, r + 1, c + 2));
                    finished = true;
                    break;
                }
            }
        }

    assert(finished);
    output();
}