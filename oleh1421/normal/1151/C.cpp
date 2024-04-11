#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const long long mod=1000000007ll;
ll f(ll x){
   ll cnt1=0;
   ll cnt2=0;
   ll cur=1ll;
   int who=0;
   ll res=0ll;
   while (cnt1+cnt2<x){
       cur=min(cur,x-cnt1-cnt2);
       if (who==0){
          res+=((2ll*cnt1+cur)%mod*(cur%mod))%mod*1ll;
          res%=mod;
          cnt1+=cur*1ll;
       } else {
          res+=((2ll*cnt2+cur+1ll)%mod*(cur%mod))%mod*1ll;
          res%=mod;
          cnt2+=cur;
       }
       who^=1;
       cur*=2ll;
   }
   return res%mod;
}
int main()
{
   ll l,r;cin>>l>>r;
   //cout<<f(1000000000000000000)<<endl;
   cout<<(f(r)-f(l-1ll)+mod)%mod;

   return 0;
}