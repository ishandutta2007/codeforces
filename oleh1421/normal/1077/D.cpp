#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

pair<ll,ll>used[200001];
int main()
{
   ll n,k,m,s=0;
   cin>>n>>k;
   ll a[n];
   for (int i=1;i<=200000;i++) used[i].second=i;
   for (ll i=0;i<n;i++) {
        cin>>a[i];
        used[a[i]].first++;
   }
   sort(used,used+200001);
   reverse(used,used+200001);
   vector<pair<ll,ll> >ans;
   for (int i=0;i<k;i++) ans.push_back(used[i]);
   for (int i=n/k;i>=1;i--){
        m=0;
        vector<ll>ans1;
        ans1.clear();
        for (int j=0;j<ans.size();j++){
            m+=ans[j].first/i;
            for (int k=0;k<ans[j].first/i;k++) ans1.push_back(ans[j].second);
        }
        if (m>=k){
            for (int j=0;j<k;j++) cout<<ans1[j]<<" ";
            return 0;
        }
   }
   return 0;
}