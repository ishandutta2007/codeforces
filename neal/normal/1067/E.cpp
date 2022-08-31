#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

struct result {
    long long free, busy, sum;

    long long count() const {
        return free + busy;
    }
};

int N;
vector<vector<int>> adj;

result extend(result root) {
    root.busy = (root.busy + root.count()) % MOD;
    root.sum = 2 * root.sum % MOD;
    return root;
}

result merge(const result &root, const result &child) {
    result answer;
    answer.free = root.free * child.busy % MOD;
    answer.busy = (root.count() * child.count() - answer.free) % MOD;
    answer.sum = (root.sum * child.count() + child.sum * root.count() + 2 * root.free * child.free) % MOD;
    return answer;
}

result dfs(int node, int parent) {
    result answer = {1, 0, 0};

    for (int neighbor : adj[node])
        if (neighbor != parent) {
            result child = dfs(neighbor, node);
            answer = merge(answer, extend(child));
        }

    return answer;
}

int main() {
    scanf("%d", &N);
    adj.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printf("%lld\n", dfs(0, -1).sum);
}