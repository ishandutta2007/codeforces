#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const long long mod=991987651ll;
ll dp[300001];
int p[300001];
int ans[300001];
int main()
{
   int n;cin>>n;
   vector<pair<int,int> >v;
   for (int i=1;i<=n;i++){
      int x;cin>>x;
      v.push_back({x,i});
   }

   v.push_back({-1,-1});
   sort(v.begin(),v.end());
   for (int i=1;i<=n;i++) dp[i]=10000000000000001ll;
   dp[0]=0ll;
   for (int i=3;i<=n;i++){
      for (int j=max(1,i-4);j<=i-2;j++){
         ll cur=dp[j-1]+v[i].first-v[j].first;
         if (cur<dp[i]){
            dp[i]=cur;
            p[i]=j;
         }
      }
   }
   cout<<dp[n]<<" ";
   int cur=n;
   int cnt=0;
   while (cur){
      cnt++;
      for (int i=p[cur];i<=cur;i++) ans[v[i].second]=cnt;
      cur=p[cur]-1;
   }
   cout<<cnt<<endl;
   for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
   return 0;
}