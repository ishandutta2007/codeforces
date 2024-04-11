#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = (int)1e6 + 123;
const ll MOD = (ll)1e9 + 7;
ll F[N];

ll kap(ll n,int k){
  if(k==0)
    return 1;
  ll p = kap(n,k/2);
  p*=p;
  p%=MOD;
  if(k%2)p*=n;
  p%=MOD;
  return p;
}

ll inv(ll x){
  return kap(x,MOD-2);
}

ll C(int x,int y){
  ll a = F[x];
  a *= inv(F[y]);
  a %= MOD;
  a *= inv(F[x-y]);
  a %= MOD;
  return a;
}

void Solve(){
  int x,y;
  cin >> x >> y;
  if(y==1){
    cout << 1 << "\n";
    return;
  }
  ll cnt = 0;
  ll ans = 1;
  for(int i = 2;i*i<=x;i++){
    if(x%i==0){
      cnt=0;
      while(x%i==0){
	x/=i;
        cnt++;
      }  
      ans *= C(cnt+y-1,y-1);
      ans %= MOD;
    }
  }
  if(x>1)ans*=y;
  ans %= MOD;
  ans *= kap(2LL,y-1);
  ans %= MOD;
  cout << ans << "\n";
}

int main(){
  F[0]=1;
  for(int i = 1;i<N;i++)F[i]=(1LL*F[i-1]*i)%MOD;
  int q;
  cin >> q;
  while(q--)Solve();
  return 0;
}