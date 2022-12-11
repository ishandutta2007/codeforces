#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ll n,k; 
  cin >> n >> k;
  if(k==1){
    cout << n;
    return 0;
  }
  ll r = 1;
  while(r*2<=n){
    r*=2;
  }
  ll ans = 0;
  ll v = 0;
  while(r>0){
    ans+=r;
    v++;
    r/=2;
  }
  cout << ans << "\n";
  return 0;
}