#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct bipartite_union_find {
    vector<int> parent;
    vector<int> size;
    vector<bool> bipartite;
    vector<bool> edge_parity;
    int components;

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

    pair<bool, bool> different(int x, int y) {
        return unite(x, y, true);
    }

    pair<bool, bool> same(int x, int y) {
        return unite(x, y, false);
    }
};

const int MOD = 998244353;

int N;
string S;
bipartite_union_find UF;

bool different(int a, int b) {
    return UF.different(a, b).second;
}

bool same(int a, int b) {
    return UF.same(a, b).second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();
    long long total = 0;

    for (int length = 1; length < N; length++) {
        int V = N + length + 2;
        int zero = V - 2, one = V - 1;
        UF.init(V);
        bool valid = different(zero, one);

        valid &= same(0, one);
        valid &= same(N - 1, one);
        valid &= same(N, one);
        valid &= same(N + length - 1, one);

        for (int i = 1; i < N - length; i++)
            if (S[i] != '?')
                valid &= same(i, S[i] == '0' ? zero : one);

        for (int i = N - length; i < N; i++)
            if (S[i] == '0')
                valid &= same(i, i + length);
            else if (S[i] == '1')
                valid &= different(i, i + length);

        for (int i = 0, j = N - 1; i < j; i++, j--)
            valid &= same(i, j);

        for (int i = 0, j = length - 1; i < j; i++, j--)
            valid &= same(N + i, N + j);

        if (valid) {
            int components = UF.components - 1;
            long long now = 1;

            for (int i = 0; i < components; i++)
                now = 2 * now % MOD;

            total = (total + now) % MOD;
        }
    }

    cout << total << '\n';
}