#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
vector<pair<int,ll> >g[500011];
int n,k;
ll dp[500011][2];
void dfs(int v,int pr){
     vector<ll>u;
     for (auto x:g[v]){
         int to=x.first;
         ll w=x.second;
         if (to==pr) continue;
         dfs(to,v);
         u.push_back(dp[to][0]+w-dp[to][1]);
         dp[v][1]+=dp[to][1];
         dp[v][0]+=dp[to][1];
     }
     sort(u.begin(),u.end());
     reverse(u.begin(),u.end());
     for (int i=0;i<u.size();i++) {
         if (i<k && u[i]>0) dp[v][1]+=u[i]*1ll;
     }
     for (int i=0;i<min((int)u.size(),k-1);i++){
         if (i<k-1 && u[i]>0) dp[v][0]+=u[i]*1ll;
     }

}
void solve(){
    int n;cin>>n>>k;
    for (int i=0;i<=n;i++) for (int j=0;j<2;j++) dp[i][j]=0;
    for (int i=1;i<n;i++){
        int a,b,w;cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    dfs(1,0);
    cout<<dp[1][1]<<endl;
    for (int i=0;i<=n;i++) g[i].clear();
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}