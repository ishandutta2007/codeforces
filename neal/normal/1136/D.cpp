#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> rev;
vector<vector<int>> adj;
vector<bool> nastya_skip;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.assign(N, {});
    rev.assign(N, -1);

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        p--;
        rev[p] = i;
    }

    nastya_skip.assign(N, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        u = rev[u];
        v = rev[v];
        adj[u].push_back(v);

        if (v == N - 1)
            nastya_skip[u] = true;
    }

    int total = 0;
    int non_skip = 0;

    for (int i = N - 2; i >= 0; i--)
        if (nastya_skip[i]) {
            int can_skip = 0;

            for (int neighbor : adj[i])
                if (neighbor > i && neighbor < N - 1 && !nastya_skip[neighbor])
                    can_skip++;

            if (can_skip >= non_skip) {
                total++;
            } else {
                nastya_skip[i] = false;
                non_skip++;
            }
        } else {
            non_skip++;
        }

    cout << total << '\n';
}