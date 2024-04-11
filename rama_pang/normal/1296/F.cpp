#include <bits/stdc++.h>
using namespace std;


vector<int> adj[5005];
int ans[5005];
pair<int, int> edge[5005];

int dfs(int cur, int p, int target, int val) {
    if (cur == target) {
        return 1;
    }
    for (auto &i : adj[cur]) {
        int nxt = cur == edge[i].first ? edge[i].second : edge[i].first;
        if (nxt == p) {
            continue;
        }
        int ok = dfs(nxt, cur, target, val);
        if (ok) {
            ans[i] = max(ans[i], val);
            return 1;
        }
    }
    return 0;
}

int check(int cur, int p, int target, int val, int minim = (int) 1e8) {
    if (cur == target) {
        if (minim == val) {
            return 1;
        }
        return 0;
    }
    for (auto &i : adj[cur]) {
        int nxt = cur == edge[i].first ? edge[i].second : edge[i].first;
        if (nxt == p) {
            continue;
        }
        int ok = check(nxt, cur, target, val, min(minim, ans[i]));
        if (ok) {
            return 1;
        }
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        edge[i] = {u, v};
        adj[u].emplace_back(i);
        adj[v].emplace_back(i);
    }
    int M;
    cin >> M;
    for (int i = 1; i < N; i++) {
        ans[i] = 1;
    }
    vector<pair<pair<int, int>, int>> inp;
    for (int i = 0; i < M; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        dfs(a, 0, b, g);
        inp.push_back({{a, b}, g});
    }

    for (int i = 0; i < M; i++) {
        int a, b, g;
        a = inp[i].first.first;
        b = inp[i].first.second;
        g = inp[i].second;

        int ok = check(a, 0, b, g);
        if (ok) {
            continue;
        }
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 1; i < N; i++) {
        cout << ans[i] << " \n"[i == N];
    }
}