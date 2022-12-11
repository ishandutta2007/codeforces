#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll inf = (ll)9e18;

ll calc(ll n){
  ll sum = 0;
  while(n>0){
    sum+=n%10;
    n/=10;
  }
  return sum;
}

void solve(){
  int n, k;
  cin >> n >> k;
  k ++ ;
  ll c1 = inf;
  ll sum;
  ll vv;
  ll res;
  for(int i = 0 ; i + k <= 10; i ++ ){
    sum = 0;
    for(int j = 0 ; j < k ; j ++ )
      sum += i + j;
    if(sum <= n && (n - sum) % k == 0){
      vv = (n - sum) / k;
      res = (vv % 9ll);
      for(int j = 0 ; j < vv/9; j ++ )
        res=(res*10ll)+9;
      res=(res*10ll)+i;
      c1=min(c1,res);
    }
  }
  int lat;
  for(int las = 0 ; las <= 9; las ++ ){
    if(las + k <= 10) continue;
    for(int nin = 0; nin <= 18; nin ++ ){
      for(int aft = 0 ; aft <= 8; aft ++ ){
        ll cc = 0;
        lat = 0;
        for(int j = 0 ;j < k ; j ++ ){
          cc += (las + j) % 10;
          if(las + j <= 9){
            cc += nin * 9ll;
            cc += aft;
          }
          else{
            lat ++ ;
            cc += (aft + 1);
          }
        }
        if(cc > n || (n - cc) % k != 0) continue;
        vv = (n - cc) / k;
        res=(vv%9);
        for(int j = 0 ; j < vv/9ll; j ++ )
          res=(res*10ll)+9;
        res=(res*10ll)+aft;
        for(int j = 0 ; j < nin; j ++ )
          res=(res*10ll)+9;
        res=(res*10ll)+las;
        c1=min(c1,res);
      }
    }
  }
  if(c1 == inf)
    cout << -1 << "\n";
  else
    cout << c1 << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t =0 ; t < tc; t++ )
    solve();
  return 0;
}