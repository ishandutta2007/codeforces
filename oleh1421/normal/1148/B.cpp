#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200003];
ll b[200003];
ll n,m,ta,tb,k;
bool ok(ll x){
     ll cnt=0ll;
     x-=tb;
     int last=0;
     for (int i=1;i<=m;i++){
         if (b[i]<=x) last=i;
     }
    // cout<<x+tb<<" "<<last<<endl;
    if (last<=k) return false;
     for (int i=1;i<=last;i++){
         int cur=(upper_bound(a+1,a+n+1,b[i])-a);
         if (last-i+cur-1<=k) {
              //  cout<<i<<endl;
                return false;
         }
     }
     return true;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   cin>>n>>m>>ta>>tb>>k;
   for (int i=1;i<=n;i++) cin>>a[i];
   for (int i=1;i<=n;i++) a[i]+=ta;
   a[n+1]=4000000001ll;  for (int i=1;i<=m;i++) cin>>b[i];
  // cout<<ok(4)<<endl;
   ll l=1ll;
   ll r=4000000001ll;
   if (!ok(r)){
        cout<<-1;
        return 0;
   }
   while (r-l>1){
       ll mid=(r+l)/2ll;
       if (ok(mid)) r=mid;
       else l=mid;
   }
   if (ok(l)) cout<<l;
   else cout<<r;
   return 0;
}
/*
2 2 1 1 1
1 2
3 4
*/