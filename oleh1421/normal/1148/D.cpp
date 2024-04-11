#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300001];
int b[300001];
bool cmpb(int cur1,int cur2){
    return (b[cur1]<b[cur2]);
}
bool cmpa(int cur1,int cur2){
    return (a[cur1]<a[cur2]);
}
int dp[300001];
int pr[300001];
int dp1[300001];
int pr1[300001];
map<pair<int,int>,int>mp;
int32_t main() {
   int n;cin>>n;
   vector<pair<int,int> >v;
   vector<pair<int,int> >u;
   for (int i=1;i<=n;i++){
       cin>>a[i]>>b[i];
       mp[{a[i],b[i]}]=i;
       mp[{-a[i],-b[i]}]=i;
       if (a[i]<b[i]) v.push_back({a[i],b[i]});
       else u.push_back({a[i],b[i]});
   }
   for (int i=0;i<v.size();i++){
       v[i].first*=(-1);
       v[i].second*=(-1);
   }
   sort(v.begin(),v.end());
   for (int i=0;i<v.size();i++) dp[i+1]=1;
   for (int i=0;i<(int)v.size()-1;i++){

       pair<int,int>cur={v[i].second,-1000000};
       int j=(lower_bound(v.begin(),v.end(),cur)-v.begin());
       j=max(j,i+1);
   //5
       if (dp[j+1]<dp[i+1]+1){
           dp[j+1]=dp[i+1]+1;
           pr[j+1]=i+1;
       }
   }
   int index=0;
   for (int i=0;i<v.size();i++){
       if (dp[i+1]>dp[index]) index=i+1;
   }
   vector<int>resv;
   while (index){
        resv.push_back(mp[v[index-1]]);
        index=pr[index];
   }
   reverse(resv.begin(),resv.end());
   sort(u.begin(),u.end());
   for (int i=0;i<u.size();i++) dp1[i]=1;
   for (int i=0;i<(int)u.size()-1;i++){
       pair<int,int>cur={u[i].second,-1};
       int j=lower_bound(u.begin(),u.end(),cur)-u.begin();
       j=max(j,i+1);
       if (dp1[j+1]<dp1[i+1]+1){
           dp1[j+1]=dp1[i+1]+1;
           pr1[j+1]=i+1;
       }
   }
   int index1=0;
   for (int i=0;i<u.size();i++){
       if (dp1[i+1]>dp1[index1]) index1=i+1;
   }
   vector<int>resu;
   while (index1){
        resu.push_back(mp[u[index1-1]]);
        index1=pr1[index1];
   }
   reverse(resu.begin(),resu.end());
   vector<int>ans;
   if (resu.size()>resv.size()) ans=resu;
   else ans=resv;
   cout<<ans.size()<<endl;
   for (auto i:ans) cout<<i<<" ";
   return 0;
}