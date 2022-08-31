#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

struct result {
    // used = number of configurations where the root is used
    // not_used = number of configurations where the root is not_used
    // required = number of configurations where a path up to the root is required
    long long used = 0, not_used = 1, required = 0;

    long long either() const {
        return (used + not_used) % MOD;
    }
};

int N;
vector<int> parent;
vector<vector<int>> children;

const result &extend(const result &root) {
    return root;
}

result attach(const result &root, const result &child) {
    result answer;

    answer.not_used = root.not_used * child.either() % MOD;
    answer.used = (root.used * child.either() + root.required * child.required) % MOD;
    answer.required = (root.required * child.either() + root.required * child.required + root.not_used * child.required) % MOD;

    return answer;
}

result dfs(int node) {
    result answer;
    answer.required = children[node].empty() ? 1 : 0;

    for (int child : children[node]) {
        result child_result = dfs(child);
        answer = attach(answer, extend(child_result));
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    parent.assign(N, -1);
    children.assign(N, vector<int>());

    for (int i = 1; i < N; i++) {
        cin >> parent[i];
        parent[i]--;
        children[parent[i]].push_back(i);
    }

    cout << dfs(0).either() << '\n';
}