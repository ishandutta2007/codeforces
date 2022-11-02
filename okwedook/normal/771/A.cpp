#include <bits/stdc++.h>

using namespace std;

vector<int> G[150000];
vector<bool> used(150000);
int n, m;
long long sum = 0, cnt = 0;

void dfs(int v) {
    used[v] = true;
    ++cnt;
    sum += G[v].size();
    for (auto i : G[v])
        if (!used[i])
            dfs(i);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u - 1].push_back(v - 1);
        G[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n; ++i) 
        if (!used[i]) {
            sum = cnt = 0;
            dfs(i);
            if (sum != cnt * (cnt - 1)) {
                cout << "NO";
                return 0;
            }
        }
    cout << "YES";
    //system("pause");
    return 0;
}