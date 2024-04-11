#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int BITS = 60;

struct tree_node {
    int child[2] = {-1, -1};
    bool full = false;
};

struct tree {
    vector<tree_node> nodes = {tree_node()};

    int get_or_create_node(int &node) {
        int answer = node;

        if (node < 0) {
            answer = node = nodes.size();
            nodes.emplace_back();
        }

        // node may no longer be a valid variable after calling `emplace_back`.
        return answer;
    }

    void recursive_add(int node, int bit, long long prefix, long long start, long long end) {
        long long after = prefix + (1LL << bit);

        if (start <= prefix && after <= end) {
            nodes[node].full = true;
            return;
        }

        if (bit <= 0)
            return;

        long long mid = (prefix + after) / 2;
        if (start < mid) recursive_add(get_or_create_node(nodes[node].child[0]), bit - 1, prefix, start, end);
        if (end > mid) recursive_add(get_or_create_node(nodes[node].child[1]), bit - 1, mid, start, end);
    }

    void add_range(long long L, long long R) {
        recursive_add(0, BITS, 0, L, R);
    }
};

tree a_tree, b_tree;
vector<pair<int, int>> options[BITS + 1];

long long dfs_sum(int bit, long long prefix) {
    for (pair<int, int> &p : options[bit])
        if (a_tree.nodes[p.first].full || b_tree.nodes[p.second].full) {
            long long count = 1LL << bit;
            long long prefix_sum = (prefix % MOD) * (count % MOD);
            long long bit_sum = (count / 2 % MOD) * ((count - 1) % MOD);
            return (prefix_sum + bit_sum) % MOD;
        }

    if (bit <= 0)
        return 0;

    long long sum = 0;

    for (int next = 0; next < 2; next++) {
        options[bit - 1].clear();

        for (pair<int, int> &p : options[bit])
            for (int left = 0; left < 2; left++) {
                int right = left ^ next;
                int a_child = a_tree.nodes[p.first].child[left];
                int b_child = b_tree.nodes[p.second].child[right];

                if (a_child >= 0 && b_child >= 0)
                    options[bit - 1].emplace_back(a_child, b_child);
            }

        if (!options[bit - 1].empty()) {
            long long add = (long long) next << (bit - 1);
            sum = (sum + dfs_sum(bit - 1, prefix + add)) % MOD;
        }
    }

    return sum;
}

int main() {
    int A, B;
    cin >> A;

    for (int i = 0; i < A; i++) {
        long long L, R;
        cin >> L >> R;
        R++;
        a_tree.add_range(L, R);
    }

    cin >> B;

    for (int i = 0; i < B; i++) {
        long long L, R;
        cin >> L >> R;
        R++;
        b_tree.add_range(L, R);
    }

    options[BITS].emplace_back(0, 0);
    cout << dfs_sum(BITS, 0) << '\n';
}