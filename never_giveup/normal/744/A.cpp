#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100, inf = 1e9 + 100;

bool vis[maxn];

int n, m, k, a[maxn];

int mx;

vector<int> e[maxn];

int sz;

int answer;

int rem;

void dfs(int v){
    vis[v] = 1;
    sz++;
    rem += e[v].size();
    for (int i = 0; i < e[v].size(); i++)
        if (!vis[e[v][i]])
            dfs(e[v][i]);
}

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i], a[i]--;
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    for (int i = 0; i < k; i++){
        sz = 0;
        rem = 0;
        dfs(a[i]);
        answer += sz * (sz - 1) / 2 - rem / 2;
        mx = max(mx, sz);
    }
    rem = 0;
    sz = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            rem += e[i].size(), sz++;
    answer += sz * (sz - 1) / 2 - rem / 2;
    answer += sz * mx;
    cout << answer;
}