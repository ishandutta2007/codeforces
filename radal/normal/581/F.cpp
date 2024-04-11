#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=5e3+30,mod = 1e9+7,inf=2e8;
const long double eps = 0.0001;
vector <int> adj[N];
int dp[N][N][2],tmp[N][2],leaf[N];
void pre(int v,int p){
    if (adj[v].size() == 1){
        leaf[v] = 1;
        return;
    }
    for(int u : adj[v]){
        if (u != p){
            pre(u,v);
            leaf[v]+=leaf[u];
        }
    }
    return;
}
void dfs(int v,int p){
    if (adj[v].size() == 1){
        dp[v][1][1] = 0;
        dp[v][0][0] = 0;
        dp[v][1][0] = inf;
        dp[v][0][1] = inf;
        return;
    }
    for (int u : adj[v]){
        if (u == p) continue;
        dfs(u,v);
        rep(i,0,leaf[v]+1){
            tmp[i][0] = dp[v][i][0];
            tmp[i][1] = dp[v][i][1];
            dp[v][i][1] = inf;
            dp[v][i][0] = inf;
        }
        rep(i,0,leaf[v]+1){
            rep(j,0,min(i,leaf[u])+1){
                dp[v][i][0] = min(dp[v][i][0],tmp[i-j][0]+min(dp[u][j][0],dp[u][j][1]+1));
                dp[v][i][1] = min(dp[v][i][1],tmp[i-j][1]+min(dp[u][j][0]+1,dp[u][j][1]));
            }
        }
    }
    return;
}
int main(){
    int n;
    cin >> n;
    rep(i,0,n-1){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if (n == 2){
        cout << 1;
        return 0;
    }
    rep(i,1,n+1){
        rep(j,1,N){
            dp[i][j][1] = inf;
            dp[i][j][0] = inf;
        }
    }
    int sc=1;
    rep(i,1,n+1){
        if (adj[i].size() != 1){
            sc = i;
            break;
        }
    }
    pre(sc,-1);
    dfs(sc,-1);
    cout << min(dp[sc][leaf[sc]/2][0],dp[sc][leaf[sc]/2][1]);
    return 0;
}