#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
const ll inf=1e14+1ll;
int a[N];
vector<int>g[N];
ll sum[N];
vector<int>order;
int n,k;
int Xr=0;
int dp[N][40];
void dfs(int v,int pr){
    for (int i=0;i<k*2;i++){
        if (i>=k) dp[v][i]=a[v];
        else dp[v][i]=0;
    }
    for (int to:g[v]){
        if (to!=pr){
            dfs(to,v);
            for (int i=0;i<k*2;i++){
                dp[v][i]^=dp[to][(i+1)%(k*2)];
            }
        }
    }
}
int ans[N];
void dfs1(int v,int pr){
    ans[v]=(dp[v][0]>0);
    for (int to:g[v]){
        if (to!=pr){
            for (int i=0;i<k*2;i++){
                dp[v][i]^=dp[to][(i+1)%(k*2)];
            }
            for (int i=0;i<k*2;i++){
                dp[to][i]^=dp[v][(i+1)%(k*2)];
            }
            dfs1(to,v);
            for (int i=0;i<k*2;i++){
                dp[to][i]^=dp[v][(i+1)%(k*2)];
            }
            for (int i=0;i<k*2;i++){
                dp[v][i]^=dp[to][(i+1)%(k*2)];
            }
        }
    }
}
void solve(){
    cin>>n>>k;
    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0);
    dfs1(1,0);
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}