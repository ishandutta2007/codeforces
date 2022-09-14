#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
typedef long long ll;
using namespace std;
int a[200001];
vector<int>g[200001];
map<int,int>dp[200001];
int res=0ll;
int used[200001];
void dfs(int v,int pr){
     for (auto to:g[v]) if (to!=pr) dfs(to,v);
     vector<int>p;
     int x=a[v];
     while (x>1){
          dp[v][used[x]]=1;
          res=max(res,1ll);
          x/=used[x];
     }
     for (auto to:g[v]){
         if (to==pr) continue;
         for (auto x:dp[to]){
             if (a[v]%x.first) continue;
             res=max(res,dp[v][x.first]+x.second);
             dp[v][x.first]=max(x.second+1,dp[v][x.first]);
         }
     }

}
int32_t main() {
    int N=200000;
    for (int i=2;i<=N;i++) used[i]=i;
    for (int i=2;i*i<=N;i++){
        if (used[i]==i){
            for (int j=i*i;j<=N;j+=i){
                used[j]=min(used[j],i);
            }
        }
    }
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout<<res;
    return 0;
}