#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> adj;
vector<array<int, 2>> dp;

int dfs(int node, int parent) {
    int best = 1, second_best = 1, children = 0, answer = 0;

    for (int neighbor : adj[node])
        if (neighbor != parent) {
            answer = max(answer, dfs(neighbor, node));
            children++;

            if (dp[neighbor][0] > second_best) {
                second_best = dp[neighbor][0];

                if (second_best > best)
                    swap(best, second_best);
            }
        }

    dp[node][0] = 1 + best + (children - 1);
    dp[node][1] = 1 + best + second_best + (children - 2);
    answer = max(answer, dp[node][1] + (parent >= 0 ? 1 : 0));
    return answer;
}

void solve_case() {
    cin >> N;
    adj.assign(N, {});
    dp.assign(N, {1, 1});

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << dfs(0, -1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}