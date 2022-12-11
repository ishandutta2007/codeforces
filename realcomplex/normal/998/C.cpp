#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

int main(){
  fastIO;
  int n;
  ll x,y;
  cin >> n >> x >> y;
  string s;
  cin >> s;
  int z = 0;
  ll seg =0 ;
  for(int i = 0;i < n; i++){
    if(s[i] == '0'){
      z ++ ;
    }
    if(s[i] == '1' or i + 1 == n){
      if(z > 0) seg ++ ;
      z = 0;
    }
  }
  ll ans = (ll)1e18;
  if(seg == 0)
    ans = 0;
  ll ch;
  for(ll i = 0;i < seg;i ++ ){
    ch = seg - i; // segm
    ans = min(ans, (ch * y) + (x * i));
  }
  cout << ans;
  return 0;
}