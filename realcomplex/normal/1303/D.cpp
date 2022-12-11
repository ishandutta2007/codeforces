#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

const int LOG = 62;
const int N = (int)1e5 + 9;
ll c[LOG];
ll op[LOG];

void solve(){
  for(ll i = 0 ; i < LOG; i ++ )
    c[i]=op[i]=0;
  ll n;
  ll m;
  cin >> n >> m;
  for(ll i = 0 ; i < LOG; i ++ )
    if((n & (1ll << i)))c[i]++;
  ll x;
  for(ll i = 0 ; i < m; i ++ ){
    cin >> x;
    for(ll j = 0 ; j < LOG; j ++ )
      if((x & (1ll << j)))op[j]++;
  }
  ll res = 0;
  ll r;
  for(ll i = 0 ; i < LOG; i ++ ){
    if(c[i] == 0) continue;
    r = 1;
    for(ll j = i; j >= 0 ; j -- ){
      if(r > m) break;
      if(op[j] >= r){
        c[i]=0;
        op[j] -= r;
        for(ll f = j + 1; f <= i ; f ++ ){
          op[f]=0;
        }
        break;
      }
      else{
        r-=op[j];
        r*=2ll;
      }
    }
    if(c[i] == 1){
      for(ll j = i; j < LOG; j ++ ){
        if(op[j] >= 1){
          c[i]=0;
          op[j]--;
          res += j - i;
          for(int x = i ; x < j ;x ++ )
            op[x]=1;
          break;
        }
      }
    }
    if(c[i] == 1){
      cout << "-1\n";
      return;
    }
  }
  cout << res << "\n";
}

int main(){ 
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){  
    solve();
  }
  return 0;
}