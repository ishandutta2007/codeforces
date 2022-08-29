// Solution to https://codeforces.com/contest/1249/problem/F
#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

template<typename T1, typename T2>
bool maximize(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }

    return false;
}

struct result {
    // dp[d] = the maximum possible weight when choosing some nodes out of our subtree such that the highest node
    // (closest to the root) has depth at least d. In particular, dp[d] >= dp[d + 1] for all d.
    deque<int> dp;

    result(int value = 0) {
        dp = {value};
    }

    int size() const {
        return (int) dp.size();
    }
};

int N, K;
vector<int> A;
vector<vector<int>> adj;
vector<result> results;

void extend(result &root) {
    // Shift the d dimension up by one.
    root.dp.push_front(root.dp.front());
}

void attach(result &root, result &child) {
    if (root.size() < child.size())
        swap(root, child);

    vector<int> combined_dp = vector<int>(child.dp.begin(), child.dp.end());

    for (int x = 0; x < child.size(); x++) {
        int min_other = max(K - x, x);

        if (min_other < child.size())
            maximize(combined_dp[x], root.dp[x] + child.dp[min_other]);

        if (min_other < root.size())
            maximize(combined_dp[x], root.dp[min_other] + child.dp[x]);
    }

    int maximum = 0;

    for (int i = child.size() - 1; i >= 0; i--) {
        maximum = max(maximum, combined_dp[i]);
        maximize(root.dp[i], maximum);
    }
}

void dfs(int node, int parent) {
    result &answer = results[node];
    answer = result(A[node]);

    for (int neighbor : adj[node])
        if (neighbor != parent) {
            dfs(neighbor, node);
            extend(results[neighbor]);
            attach(answer, results[neighbor]);
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    K++;
    A.resize(N);
    adj.assign(N, {});

    for (auto &a : A)
        cin >> a;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    results.assign(N, {});
    dfs(0, -1);
    cout << results[0].dp.front() << '\n';
}