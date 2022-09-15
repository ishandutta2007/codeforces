#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll x[300001];
ll p[300001];
ll mmm(ll a,ll b){
   ll res=(a%b)*1ll;
   if (res==0) res=b;
   return res;
}
int main()
{
   int n,m;cin>>n>>m;
   ll maxx=0ll;
   ll minx=1000000000000000000ll;
   for (int i=1;i<=n;i++){
       cin>>x[i];
       maxx=max(maxx*1ll,x[i]*1ll);
       minx=min(minx*1ll,x[i]*1ll);
   }
   sort(x+1,x+n+1);
   for (int i=1;i<=m;i++){
       cin>>p[i];
   }
   ll g=(x[2]-x[1])*1ll;
   for (int i=3;i<=n;i++){
       g=__gcd(g*1ll,(x[i]-x[i-1])*1ll);
   }
   for (int i=1;i<=m;i++){
      if (g%p[i]==0 && mmm(x[1],p[i])<=minx){
         cout<<"YES"<<endl<<mmm(x[1],p[i])<<" "<<i;
         return 0;
      }
   }
   cout<<"NO";
   return 0;
}