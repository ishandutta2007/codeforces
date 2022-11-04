#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1];
int cnt[MAXN + 1];
bool vis[MAXN + 1];

void dfs(int nod, int lvl) {
    cnt[lvl]++;
    vis[nod] = 1;
    for(auto it : g[nod]) {
        if(vis[it] == 0)
            dfs(it, lvl + 1);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(true);
    cin >> n;
    for(i = 2; i <= n; i++) {
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1, 1);
    int ans = 0;
    for(i = 1; i <= n; i++) {
        ans += cnt[i] % 2;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}