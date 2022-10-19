#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn=507;
const int INF=1e9;
int t;
int n,m,k;
int b[maxn][maxn],c[maxn][maxn],d[maxn][maxn][12];
bool vis[maxn][maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    if (k&1){
        rep1(i,n) rep1(j,m) cout<<-1<<" ";
        return 0;
    }
    k/=2;
    rep1(i,n) rep1(j,m-1) cin>>b[i][j];
    rep1(i,n-1) rep1(j,m) cin>>c[i][j];
    rep1(i,n) rep1(j,m) rep1(s,k) d[i][j][s]=INF;
    rep1(s,k) rep1(i,n) rep1(j,m){
            if (i>1) d[i-1][j][s]=min(d[i-1][j][s],d[i][j][s-1]+c[i-1][j]);
            if (i<n) d[i+1][j][s]=min(d[i+1][j][s],d[i][j][s-1]+c[i][j]);
            if (j>1) d[i][j-1][s]=min(d[i][j-1][s],d[i][j][s-1]+b[i][j-1]);
            if (j<m) d[i][j+1][s]=min(d[i][j+1][s],d[i][j][s-1]+b[i][j]);  
    }
    rep1(i,n) rep1(j,m){
        int dp[20];
        dp[0]=0;
        rep1(s,k) dp[s]=INF;
        rep1(s,k) rep(t,s) dp[s]=min(dp[s],dp[t]+d[i][j][s-t]);
        cout<<dp[k]*2<<" ";
    }
    return 0;
}