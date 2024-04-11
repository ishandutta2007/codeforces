#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> rpos;
vector<int> G[1000005];
pair<int, int> ans[1000005];

void dfs(int n = 1, int p = 0) {
    for (auto i : G[n]) if (i != p) {
        rpos.emplace_back(i);
    }
    rpos.emplace_back(n);
    reverse(G[n].begin(), G[n].end());
    for (auto i : G[n]) if (i != p) {
        dfs(i, n);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    rpos.emplace_back(1);
    dfs();

    for (int i = 0; i < N + N; i++) {
        if(ans[rpos[i]].first == 0) {
            ans[rpos[i]].first = i + 1;
        } else {
            ans[rpos[i]].second = i + 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}