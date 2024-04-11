#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll s[30];

ll fin2(ll n){
  if(n==1) return 2;
  ll p;
  for(int i = 1; i < 30 ; i ++ ){
    if(s[i] >= n){
      if(i>=2)p = s[i-2]+(n-s[i-1]+3)/4;
      else p = 1;
      p = fin2(p);
      if((n-s[i-1])%4==1) return 4ll*p;
      else if((n-s[i-1])%4==2) return 4ll*p+2;
      else if((n-s[i-1])%4==3) return 4ll*p+3;
      else return 4ll*p+1;
    }
  }
  
}

ll fin(ll n){
  if(n % 3 == 1){
    ll l, r;
    n = (n+2)/3;
    for(ll i = 0 ; i <= 58; i += 2 ){
      l = (1ll << i);
      r = (1ll << (i+1)) - 1;
      if(r - l + 1 < n){
        n -= (r - l + 1);
      }
      else{
        return l + n - 1;
      }
    }
  }
  else if(n % 3 == 2){
    return fin2((n+1)/3);
  }
  else if(n % 3 == 0){
    return (fin(n-1) ^ fin(n-2));
  }
}

int main(){
  fastIO;
  s[0] = 1;
  for(int i = 1; i < 30 ;i  ++ ){
    s[i] = (s[i-1] + (1ll << (2*i)));
  }
  int q;
  cin >> q;
  ll n;
  for(int i = 0 ; i < q; i ++ ){
    cin >> n;
    cout << fin(n) << "\n";
  }
  return 0;
}