#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int INF = 1e8;

int N;
int A[400005];
vector<int> G[400005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < N; i++) {
        if (i + A[i] < N) {
            G[i + A[i]].emplace_back(i);
        }
        if (0 <= i - A[i]) {
            G[i - A[i]].emplace_back(i);
        }
    }

    vector<int> ans(N, -1);
    queue<pair<int, int>> q;
    vector<int> vis(N, 0);
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 0) continue;
        vis[i] = 1;
        q.emplace(i, 0);
    }

    while (!q.empty()) {
        int f = q.front().first;
        int w = q.front().second;
        q.pop();
        if (A[f] % 2 == 0) ans[f] = w;
        for (auto i : G[f]) {
            if (vis[i] == 0) {
                q.emplace(i, w + 1);
                vis[i] = 1;
            }
        }
    }

    vis.assign(N, 0);
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 1) continue;
        vis[i] = 1;
        q.emplace(i, 0);
    }

    while (!q.empty()) {
        int f = q.front().first;
        int w = q.front().second;
        q.pop();
        if (A[f] % 2 == 1) ans[f] = w;
        for (auto i : G[f]) {
            if (vis[i] == 0) {
                q.emplace(i, w + 1);
                vis[i] = 1;
            }
        }
    }
    
    
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }

    return 0;
}

/*
5
2 1 2 1 1


*/