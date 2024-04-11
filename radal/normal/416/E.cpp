#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
typedef pair<ll,ll> pll;
const long long int N=5e2+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
ll dp[N][N],a[N][N];
int out[N];
pair<pll,ll> edge[N*N];
int n,m;
int main(){
    memset(dp,63,sizeof dp);
    //memset(a,-1,sizeof a);
    cin >> n >> m;
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        edge[i] = {{u,v},w};
        dp[u][v] = w;
        dp[v][u] = w;
    }
    rep(i,1,n+1) dp[i][i] = 0;
    rep(i,1,n+1){
        rep(j,1,n+1){
            rep(k,1,n+1){
                dp[j][k] = min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }
    rep(i,1,n+1){
        memset(out,0,sizeof out);
        rep(j,0,m){
            ll u = edge[j].X.X,v = edge[j].X.Y,w = edge[j].Y;
            if (w+dp[v][i] == dp[u][i]){
                out[u]++;
            }
            if (w+dp[u][i] == dp[v][i]){
                out[v]++;
            }
        }
        rep(j,1,n+1){
            rep(k,1,n+1){
                if (dp[k][j]+dp[j][i] == dp[k][i]) a[i][k] += out[j];
            }
        }
    }
    rep(i,1,n){
        rep(j,i+1,n+1){
            cout << a[i][j] << ' ';
        }
    }
    return 0;
}