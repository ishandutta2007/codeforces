#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

struct result {
    long long matched, needs, single;

    result() : matched(0), needs(0), single(0) {}

    long long unmatched() const {
        return needs + single;
    }

    long long good_count() const {
        return matched + single;
    }
};

int N;
vector<vector<int>> adj;

const result &extend(const result &root) {
    return root;
}

result attach(const result &root, const result &child) {
    result answer;

    // Delete the edge.
    answer.matched = root.matched * child.good_count();
    answer.needs = root.needs * child.good_count();
    answer.single = root.single * child.good_count();

    // Keep the edge.
    answer.matched += root.matched * child.matched + root.unmatched() * child.unmatched();
    answer.needs += root.unmatched() * child.matched;

    answer.matched %= MOD;
    answer.needs %= MOD;
    answer.single %= MOD;
    return answer;
}

result dfs(int node, int parent) {
    result answer;
    answer.single = 1;

    for (int neighbor : adj[node])
        if (neighbor != parent) {
            result child = dfs(neighbor, node);
            answer = attach(answer, extend(child));
        }

    return answer;
}

int main() {
    scanf("%d", &N);
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printf("%lld\n", dfs(0, -1).good_count() % MOD);
}