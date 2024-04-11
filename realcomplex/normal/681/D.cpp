#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
bool vis[N];
vector<int> T[N];

bool gift[N];

vector<int> lis;
int pos[N];

void dfs(int u){
    if(vis[u])
        return;
    vis[u] = true;
    for(auto x : T[u]){
        dfs(x);
    }
    if(gift[u]){
        pos[u] = lis.size();
        lis.push_back(u);
    }
}

int w[N];
int dg[N];

void dfs2(int u, int mi, int id){
    if(vis[u])
        return;
    vis[u] = true;
    if(gift[u] && pos[u] < mi)
        mi = pos[u], id = u;
    if(w[u] != id){
        cout << -1;
        exit(0);
    }
    for(auto x : T[u])
        dfs2(x, mi, id);
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0 ;i  < m ; i ++ ){
        cin >> u >> v;
        dg[v] ++ ;
        T[u].push_back(v);
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> w[i];
        gift[w[i]] = true;
    }
    for(int i = 1; i <= n;i ++ )
        if(dg[i] == 0)dfs(i);
    for(int i = 1; i <= n; i ++ ) vis[i] = false;
    for(int i = 1; i <= n; i ++ )
        if(dg[i] == 0)dfs2(i, (int)1e9, -1);
    cout << lis.size() << "\n";
    for(auto x : lis)  cout << x << "\n";
    return 0;
}