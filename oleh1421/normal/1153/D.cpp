#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c[300001];
vector<int>g[300001];
int dp[300001];
int cnt=0;
void dfs(int v){
     if (g[v].empty()){
        dp[v]=1;
        cnt++;
        return;
     }
     for (auto to:g[v]) dfs(to);
     if (c[v]==0){
        for (auto to:g[v]) dp[v]+=dp[to];
     } else {
        dp[v]=100000001;
        for (auto to:g[v]) dp[v]=min(dp[v],dp[to]);
     }
}
int main() {
   int n;cin>>n;
   for (int i=1;i<=n;i++) cin>>c[i];
   for (int i=2;i<=n;i++){
       int f;cin>>f;
       g[f].push_back(i);
   }
   dfs(1);

   cout<<cnt-dp[1]+1;
   return 0;
}
/*
6 7
1 2
2 3
1 3
4 5
5 6
4 6
3 4
*/