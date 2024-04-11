#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

int N;
vector<int> cost[3];
vector<vector<int>> adj;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int c = 0; c < 3; c++) {
        cost[c].resize(N);

        for (int i = 0; i < N; i++)
            cin >> cost[c][i];
    }

    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = -1;

    for (int i = 0; i < N; i++)
        if (adj[i].size() > 2) {
            cout << -1 << '\n';
            return 0;
        } else if (adj[i].size() == 1) {
            start = i;
        }

    vector<int> order = {start};

    while ((int) order.size() < N) {
        int current = order.back();

        for (int neighbor : adj[current])
            if (order.size() == 1 || neighbor != order[(int) order.size() - 2]) {
                order.push_back(neighbor);
                break;
            }
    }

    vector<int> perm = {0, 1, 2};
    vector<int> best_perm;
    long long best = LL_INF;

    do {
        long long score = 0;

        for (int i = 0; i < N; i++)
            score += cost[perm[i % 3]][order[i]];

        if (score < best) {
            best = score;
            best_perm = perm;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << best << '\n';
    vector<int> answer(N, -1);

    for (int i = 0; i < N; i++)
        answer[order[i]] = best_perm[i % 3];

    for (int i = 0; i < N; i++)
        cout << answer[i] + 1 << (i < N - 1 ? ' ' : '\n');
}