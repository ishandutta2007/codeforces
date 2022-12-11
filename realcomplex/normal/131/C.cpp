#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll choose(ll n,ll k){
  if(k>n)return 0;
  if(k==n)return 1;
  ll ans = 1;
  ll l = n-k;
  for(ll i = 1;i<=k;i++){
    ++l;
    ans*=l;
    ans/=i;
  }
  return ans;
}

int main(){
  ll n,m,t;
  cin >> n >> m >> t;
  ll ans = 0;
  for(ll i = 4;i<=n;i++){
    for(ll j = 1;j<=m;j++){
      if(i+j==t){
        ans+=choose(n,i)*choose(m,j);
      }
    }
  }
  cout << ans << "\n";
  return 0; 
}