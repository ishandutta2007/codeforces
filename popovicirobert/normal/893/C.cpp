#include <bits/stdc++.h>
#define lsb(x)
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;
const int INF = (int) 1e9;

vector <int> g[MAXN + 1];

bool vis[MAXN + 1];
int cst[MAXN + 1];

int mn;

void dfs(int nod) {
    vis[nod] = 1;
    mn = min(mn, cst[nod]);
    for(auto it : g[nod])
        if(vis[it] == 0)
           dfs(it);
}

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, k, x, y;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> cst[i];
    }
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            mn = INF;
            dfs(i);
            ans += mn;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}