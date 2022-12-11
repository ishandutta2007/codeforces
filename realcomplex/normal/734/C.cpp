#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

int main(){
  fastIO;
  ll n;
  int m,k;
  cin >> n >> m >> k;
  ll x, s;
  cin >> x >> s;
  pii potion[m];
  ll maxc[m + 1];
  maxc[0] = x;
  ll ans = n * x;
  for(int i = 0 ;i < m ;i ++){
    cin >> potion[i].se;
  }
  for(int i = 0;i < m; i ++ ){
    cin >> potion[i].fi;
  }
  sort(potion, potion + m);
  for(int i = 0;i < m ;i ++ ){
    maxc[i + 1] = min(maxc[i],potion[i].se);
    if(potion[i].fi <= s)
      ans = min(ans, n * potion[i].se);
  }
  pii insta[k];
  for(int i = 0;i < k; i ++ ){
    cin >> insta[i].fi;
  }
  for(int i = 0;i < k; i ++ ){
    cin >> insta[i].se;
  }
  ll mana;
  ll mak;
  ll left_potions, left_mana;
  ll cur = 0;
  int ix;
  for(int i = 0;i < k; i ++ ){
    mak = insta[i].fi;
    mana = insta[i].se;
    if( mana > s)
      break;
    left_potions =  n - mak;
    if(left_potions <= 0){
      cout << 0 << "\n";
      return 0;
    }
    left_mana = s - mana;
    ix = upper_bound(potion, potion + m, mp(left_mana,(ll)1e10)) - potion;
    ans = min(ans, left_potions * maxc[ix]);
  }
  cout << ans << "\n";
  return 0;
}