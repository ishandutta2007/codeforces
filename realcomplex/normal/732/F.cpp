#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)4e5 + 9;

vector<pii> T[N];
bool bridge[N];
int tin[N];
int low[N];
bool vis[N];
int timer;

void dfs(int u, int par){
    vis[u] = true;
    tin[u] = timer ++ ;
    low[u] = tin[u];
    for(auto x : T[u]){
        if(x.fi == par){
            continue;
        }
        if(vis[x.fi]){
            low[u] = min(low[u], tin[x.fi]);
        }
        else{
            dfs(x.fi, u);
            low[u] = min(low[u], low[x.fi]);
            if(tin[u] < low[x.fi]){
                bridge[x.se] = true;
            }
        }
    }
}

vector<int> W[N];
int sz = 0;

void dfs1(int node){
    vis[node] = true;
    sz ++ ;
    for(auto p : W[node]){
        if(vis[p])
            continue;
        dfs1(p);
    }
}

int o1[N], o2[N]; // answer

void dfs2(int node, int par){
    vis[node] = true;
    for(auto x : T[node]){
        if(x.fi == par)
            continue;
        if(vis[x.fi]){
            o1[x.se] = node;
            o2[x.se] = x.fi;
        }
        else{
            o1[x.se] = x.fi;
            o2[x.se] = node;
            dfs2(x.fi, par);
        }
    }
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int u[m], v[m];
    for(int i =0  ; i < m ; i ++ ){
        cin >> u[i] >> v[i];
        T[u[i]].push_back(mp(v[i], i));
        T[v[i]].push_back(mp(u[i], i));
    }
    dfs(1,-1);
    for(int i = 0 ; i < m ; i ++ ){
        if(!bridge[i]){
            W[u[i]].push_back(v[i]);
            W[v[i]].push_back(u[i]);
        }
    }
    for(int i = 1; i <= n; i ++ ){
        vis[i] = false;
    }
    int mx = 0;
    int nd = 0;
    for(int i = 1; i <= n ;i  ++ ){
        if(!vis[i]){
            sz = 0;
            dfs1(i);
            if(sz > mx){
                mx = sz;
                nd = i;
            }
        }
    }
    for(int i =1 ; i <= n; i ++ )
        vis[i] = false;
    dfs2(nd,-1);
    cout << mx << "\n";
    for(int i = 0 ; i < m ; i ++ ){
        cout << o1[i] << " " << o2[i] << "\n";
    }
    return 0;
}