#include <bits/stdc++.h>

using namespace std;

const int dd = (int)2e5 + 7;

vector<int> G[dd];
int used[dd], k;

int dfs(int v, int p = -1) {
    used[v] = 1;
    int ok = v >= k;
    for (int i : G[v]) if (!used[i]) {
        ok += dfs(i);
    }
    return ok;
}

int main() {
    int n;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b; --a, --b;
        G[i].push_back(k + a), G[i].push_back(k + b);
        G[k + a].push_back(i), G[k + b].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) if (!used[i]) {
        ans += dfs(i) - 1;
    }
    cout << k - ans << "\n";
    return 0;
}