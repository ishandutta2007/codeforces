#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<int> T[N];

bool vis[N];
void dfs1(int u){
    vis[u] = true;
    for(auto p : T[u]){
        if(!vis[p])
            dfs1(p);
    }
}

int tin[N];
int low[N];
int tt;
void dfs2(int u, int par){
    tin[u] = ++tt;
    low[u] = tin[u];
    for(auto x : T[u]){
        if(x == par) continue;
        if(tin[x] == -1){
            dfs2(x, u);
            low[u] = min(low[u], low[x]);
        }
        else{
            low[u] = min(low[u], tin[x]);
        }
        if(tin[u] < low[x]){
            cout << 0;
            exit(0);
        }
    }
}

bool vv[N];
void dfs3(int u, int pr){
    vv[u] = true;
    for(auto x : T[u]){
        if(x == pr) continue;
        if(vv[x] == false){
            cout << u << " " << x << "\n";
            dfs3(x, u);
        }
        else{
            if(tin[u] > tin[x]){
                cout << u << " " << x << "\n";
            }
        }
    }
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0 ;i  < m ; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs1(1);
    for(int i = 1; i <= n; i ++ ){
        if(vis[i] == false){
            cout << 0;
            return 0;
        }
        tin[i] = -1;
    }
    dfs2(1,-1);
    dfs3(1,-1);
    return 0;
}