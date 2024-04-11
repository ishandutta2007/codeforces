#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct bipartite_union_find {
    vector<int> parent;
    vector<int> size;
    vector<int> root_size;
    vector<int> root_status;
    vector<bool> bipartite;
    vector<bool> edge_parity;
    int components = 0;
    int minimum_on = 0;

    bipartite_union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        root_size.assign(n + 1, 1);
        root_status.assign(n + 1, -1);
        bipartite.assign(n + 1, true);
        edge_parity.assign(n + 1, false);
        components = n;
        minimum_on = 0;

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

    int get_other_size(int x) {
        x = find(x);
        return size[x] - root_size[x];
    }

    int get_min_size(int x) {
        x = find(x);

        if (root_status[x] >= 0) {
            if (root_status[x] == 0)
                return get_other_size(x);
            else
                return root_size[x];
        }

        return min(root_size[x], get_other_size(x));
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
        // cerr << "unite " << x << ' ' << y << ' ' << different << endl;

        int x_root = find(x);
        int y_root = find(y);

        if (x_root == y_root) {
            bool consistent = !(edge_parity[x] ^ edge_parity[y] ^ different);
            assert(consistent);

            if (!consistent)
                bipartite[x_root] = false;

            return {false, consistent};
        }

        minimum_on -= get_min_size(x);
        minimum_on -= get_min_size(y);

        bool needed_parity = edge_parity[x] ^ edge_parity[y] ^ different;
        x = x_root;
        y = y_root;

        if (size[x] < size[y])
            swap(x, y);

        if (needed_parity)
            root_size[x] += get_other_size(y);
        else
            root_size[x] += root_size[y];

        if (root_status[y] >= 0) {
            bool result = root_status[y] ^ needed_parity;
            assert(root_status[x] < 0 || root_status[x] == result);
            root_status[x] = result;
        }

        parent[y] = x;
        size[x] += size[y];
        bipartite[x] = bipartite[x] && bipartite[y];
        edge_parity[y] = needed_parity;
        components--;
        minimum_on += get_min_size(x);
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

    void set_status(int x, bool status) {
        // cerr << "set_status " << x << ' ' << status << endl;

        minimum_on -= get_min_size(x);
        int root = find(x);
        bool parity = query_parity(x, root);
        status ^= parity;
        assert(root_status[root] < 0 || root_status[root] == status);
        root_status[root] = status;
        minimum_on += get_min_size(x);
    }
};


int N, K;
string S;
vector<vector<int>> have;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> S;
    have.assign(N, {});

    for (int k = 0; k < K; k++) {
        int c;
        cin >> c;

        for (int i = 0; i < c; i++) {
            int x;
            cin >> x;
            x--;
            have[x].push_back(k);
            assert(have[x].size() <= 2);
        }
    }

    bipartite_union_find UF(K);

    for (int i = 0; i < N; i++) {
        if (have[i].size() == 1) {
            UF.set_status(have[i].front(), '1' - S[i]);
        } else if (have[i].size() == 2) {
            UF.unite(have[i].front(), have[i].back(), S[i] == '0');
        }

        cout << UF.minimum_on << '\n';
    }
}