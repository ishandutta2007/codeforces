#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const long long mod=998244353ll;
ll same[2000001];
ll dif[2000001];
ll powk[2000001];
ll n,k;
void init(){
     dif[0]=1ll;
     same[0]=0ll;
     powk[0]=1ll;
     for (int i=1;i<=n;i++){
         dif[i]=(same[i-1]+(k-2)*dif[i-1])%mod;
         same[i]=((k-1)*dif[i-1])%mod;
         powk[i]=(powk[i-1]*(k-1))%mod;
     }
}
ll f(vector<int>v){
   int last=-1;
   int cnt=0;
   ll res=1ll;
   for (auto i:v){
       if (i==-1){
          cnt++;
          continue;
       }
       if (last==-1) res*=powk[cnt];
       else if (last==i) res*=same[cnt];
       else res*=dif[cnt];
       res%=mod;
       last=i;
       cnt=0;
   }
   if (last==-1) res*=(powk[cnt-1]*k)%mod;
   else res*=powk[cnt];
   return res%mod;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    vector<int>u;
    vector<int>v;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if (i%2) v.push_back(x);
        else u.push_back(x);
    }

    init();
    cout<<(f(u)*f(v))%mod;

    return 0;
}


///20075213641185