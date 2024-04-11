#include <bits/stdc++.h>
typedef long long ll;
const long long mod=1000000007ll;
#define endl '\n'
using namespace std;
vector<int>g[5155];
vector<int>r[5155];
int a[5155];
int b[5155];
int c[5155];
int dp[5010][5010];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for (int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        r[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        g[i].push_back(i);
        r[i].push_back(i);
        sort(r[i].begin(),r[i].end());
    }
    for (int i=1;i<=n;i++){
        vector<int>v;
        for (auto to:g[i]){
            if (r[to].back()==i) v.push_back(c[to]);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        g[i]=v;
    }
    for (int i=0;i<=n;i++) for (int j=0;j<=5000;j++) dp[i][j]=-1000000001;
    dp[0][k]=0;
    for (int i=1;i<=n;i++){
        for (int j=a[i];j+b[i]<=5000;j++){
            //if (j<a[i]) continue;
            dp[i][j+b[i]]=max(dp[i][j+b[i]],dp[i-1][j]);
            int sum=0;
            for (int t=0;t<g[i].size() && t+1<=j+b[i];t++){
                sum+=g[i][t];
                dp[i][j+b[i]-t-1]=max(dp[i][j+b[i]-t-1],dp[i-1][j]+sum);
            }
        }
    }
    //cout<<dp[4][15]<<endl;
    int maxx=-1;
    for (int i=0;i<=5000;i++) maxx=max(maxx,dp[n][i]);
    cout<<maxx;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}