#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;
const long long int N=5e3+30,mod = 1e9+7,inf=1e9;
int a[N],child[N];
bool dp[N][N];
vector <int> adj[N];
int n;
void pre(int v,int p){
    for (int u : adj[v]) if (u != p){
        pre(u,v);
        child[v]+=child[u];
    }
    child[v]++;
}
void dfs(int v,int p){
    int i = 0;
    for (int u : adj[v]){
        dp[i][0] = 1;
        if (u != p){
            rep(j,1,n-1){
                dp[i][j] = 0;
                dp[i][child[u]] = 1;
                if (i) dp[i][j] = dp[i-1][j];
                if (i && j >= child[u] && dp[i-1][j-child[u]]) dp[i][j] = dp[i-1][j-child[u]];

                if (dp[i][j]){
                    a[j] = 1;
                    a[n-j-1] = 1;
                }
            }
        }
        else{
            rep(j,0,n){
                if (i) dp[i][j] = dp[i-1][j];
                else dp[i][j] = 0;
            }
            dp[0][0] = 1;
        }
        i++;
    }
    for (int u : adj[v]) if (u != p) dfs(u,v);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    pre(1,-1);
    dfs(1,-1);
    int cnt = 0;
    rep(i,1,n){
        if (a[i]) cnt++;
        //cout << child[i] << endl;
    }
    cout << cnt << endl;
    rep(i,1,n){
        if (a[i]) cout << i << ' ' << n-i-1 << endl;
    }
}