#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int32_t main() {
   ll k;cin>>k;
   ll cur=0ll;
   ll pow10=1ll;
   for (int i=1;i<=10;i++){
       ll p9=9ll*pow10;
       if (cur+p9*i*1ll>=k){
           k-=cur;
           ll x=pow10+(k/i*1ll);
           ll g=k%i;
           if (g==0) {
                g=i*1ll;
                x--;
           }
           vector<int>v;
           while (x){
              v.push_back(x%10ll);
              x/=10ll;
           }
           reverse(v.begin(),v.end());
           cout<<v[g-1]<<endl;
           return 0;
       }
       cur+=p9*i*1ll;
       pow10*=10ll;
   }
   return 0;
}