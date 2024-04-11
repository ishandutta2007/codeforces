#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;
vector<int> T[N];
bool vis[N];
int dep[N];
int soln = 0;

void dfs(int u, int par){
    vis[u]=true;
    for(auto x : T[u]){
        if(x==par) continue;
        if(vis[x]) soln += (dep[u]<dep[x]);
        else{
            dep[x]=dep[u]+1;
            dfs(x,u);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    int x, y;
    set<pii> has;
    int cnt = 0;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
        vis[i]=false;
        dep[i]=0;
    }
    soln = 0;
    for(int i = 1; i <= m; i ++ ){
        cin >> x >> y;
        if(x==y) continue;
        T[x].push_back(y);
        T[y].push_back(x);
        soln ++ ;
    }
    for(int i = 1; i <= n; i ++ ){
        if(!vis[i]) dfs(i,i);
    }
    cout << soln << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc ; t ++ ){
        solve();
    }
    return 0;
}