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
typedef pair<ll,ll> pll;
const long long int N=3e2+20,mod = 1e9+7,inf=2e8;
const long double eps = 0.0001;
int dp[N][N][N],d[N][N];
pair<pll,int> edge[N];
int main(){
    memset(dp,63,sizeof dp);
    int n;
    cin >> n;
    rep(i,1,n+1) rep(j,1,n+1) cin >> dp[i][j][0];
    /*rep(i,1,n){
        rep(j,i+1,n+1){
            bool f = 0;
            rep(k,1,n+1){
                if (k != j && k != i && d[i][k]+d[k][j] == d[i][j]){
                    f = 1;
                    break;
                }
            }
            if (!f){
                dp[i][j][0] = d[i][j];
                dp[j][i][0] = d[i][j];
            }
        }
    }*/
    int m;
    cin >> m;
    rep(i,1,n+1) dp[i][i][0] = 0;
    rep(i,1,m+1){
        int u,v,w;
        cin >> u >> v >> w;
        edge[i] = {{u,v},w};
    }
    rep(k,1,m+1){
        int u = edge[k].X.X , v = edge[k].X.Y,w = edge[k].Y;
        w = min(w,dp[u][v][k-1]);
        ll sum = 0;
        rep(i,1,n+1){
            rep(j,1,n+1){
                dp[i][j][k] = min({dp[i][j][k-1],dp[i][u][k-1]+w+dp[v][j][k-1],dp[i][v][k-1]+w+dp[j][u][k-1]});
                sum += dp[i][j][k];
            }
        }
        cout << sum/2<< ' ' ;
    }
    return 0;
}