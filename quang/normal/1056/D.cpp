#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int cnt[N];
int val[N];
int n;
vector<int> adj[N];

void dfs(int u) {
    if (adj[u].empty()) {
        val[u] = 1;
        cnt[1]++;
        return;
    }
    for (int v : adj[u]) {
        dfs(v);
        val[u] += val[v];
    }
    cnt[val[u]]++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++){ 
        for (int j = 1; j <= cnt[i]; j++) {
            cout << i << ' ';
        }        
    }
    cout << endl;
    return 0;
}