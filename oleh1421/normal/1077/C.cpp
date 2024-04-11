#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

map<ll,ll>used;
int main()
{
   ll n,ans,k,m,s=0;
   cin>>n;
   ll a[n];
   for (ll i=0;i<n;i++) {
        cin>>a[i];
        used[a[i]]++;
        s+=a[i];
   }
   ans=0;
   vector<ll>ans1;
   for (ll i=0;i<n;i++){
        s-=a[i];
        used[a[i]]--;
        if (s%2==0 && used[s/2]){
                ans++;
                ans1.push_back(i);
        }

        s+=a[i];
        used[a[i]]++;

   }
   cout<<ans<<endl;
   for (ll i=0;i<ans;i++) cout<<ans1[i]+1<<" ";
   return 0;
}