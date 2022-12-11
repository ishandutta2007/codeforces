#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// all this NT crap nobody likes

ll phi(ll x){ 
  ll pp;
  ll ans = 1;
  for(ll i = 2; i * i <= x; i ++ ){
    if(x % i != 0) continue;
    pp = 1;
    while(x % i == 0){
      x/=i;
      pp*=i;
    }
    ans *= pp/i*(i-1);
  }
  if(x!=1)ans *= (x-1);
  return ans;
}

int main(){
  fastIO;
  ll n, k;
  cin >> n >> k;
  while(k > 0){
    if(k&1)n=phi(n),k--;
    else k--;
    if(n==1) break;
  }
  cout << n % ((ll)1e9 + 7);
  return 0;
}