#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
  fastIO;
  ll n;
  cin >> n;
  ll ans = n;
  bool ok = false;
  for(ll i = 2; i * i <= n; i ++ ){
    if(n % i == 0){
      if(ok){
        ans=1;
        break;
      }
      ans=i;
      while(n%i==0)n/=i;
      ok=true;
    }
  }
  if(n>1 && ok){
    ans=1;
  }
  cout << ans;
  return 0;
}