#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;

int n, m;

int ans[2][maxn], sz[2];

int vis[maxn];

vector<int> e[maxn];

bool dfs(int v, int x){
    vis[v] = x + 1;
        ans[x][sz[x]] = v, sz[x]++;
    for (int i = 0; i < e[v].size(); i++)
        if (vis[e[v][i]] == 0){
            if (dfs(e[v][i], x ^ 1))
                return 1;
        }
        else
        if (vis[e[v][i]] == x + 1){
            return 1;
        }
    return 0;
}

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
        if (vis[i] == 0)
    if (dfs(i, 1)){
        cout << -1;
        return 0;
    }
    for (int i = 0; i < 2; i++){
        cout << sz[i] << '\n';
        for (int j = 0; j < sz[i]; j++)
            cout << ans[i][j] + 1 << ' ';
        cout << '\n';
    }
}