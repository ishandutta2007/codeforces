#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

ll n, k, ans=1, f[66][10100], g[66][10100], inv[66];

ll K(ll x,ll y=mod-2){
  ll t=1;
  for (;y;y>>=1, x=x*x%mod)
    if (y&1) t=t*x%mod;
  return t;
}

void fuck(int n,ll p){
  memset(f,0,sizeof f);
  memset(g,0,sizeof g);
  f[n][0]=1;
  ll res=0;
  for (int i=n;i>=0;--i){
    for (int j=0;j<=k;++j){
      if (j) f[i][j]=(f[i][j-1]*inv[i+1]+g[i+1][j-1])%mod;
      g[i][j]=(g[i+1][j]+f[i][j]*inv[i+1])%mod;
    }
    res=(res+K(p,i)*f[i][k])%mod;
  }
  ans=ans*res%mod;
}

int main(){
  cin>>n>>k;
  for (int i=1;i<=60;++i) inv[i]=K(i);
  for (ll i=2;i*i<=n;++i){
    if (n%i==0){
      ll c=0;
      for (;n%i==0;n/=i) ++c;
      fuck(c,i);
    }
  }
  if (n>1) fuck(1,n);
  cout<<ans<<endl;
}