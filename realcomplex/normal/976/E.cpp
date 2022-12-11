#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

int main(){
  fastIO;
  int n,a,b;
  cin >> n >> a >> b;
  ll x = (1LL << a);
  ll sum = 0;
  ll hp[n];
  ll dmg[n];
  pii st[n];
  for(int i = 0;i < n;i ++ ){
    cin >> hp[i] >> dmg[i];
    st[i] = mp(hp[i] - dmg[i],i);
    sum += dmg[i];
  }
  if(b == 0){
    cout << sum << "\n";
    return 0;
  }
  sort(st, st + n);
  reverse(st , st + n);
  b = min(b, n);
  ll tt = 0;
  for(int i = 0 ;i < b;i ++){
    tt = max(tt, tt + st[i].fi);
  }
  ll rez = sum + tt;
  int ix;
  ll ti;
  for(int i = 0;i < n;i ++ ){
    ix = st[i].se;
    if(i < b){
      ti = tt;
      ti -= max(0LL,st[i].fi);
      ti += max(0LL,(hp[ix] * x) - dmg[ix]);
      rez = max(rez, sum + ti);
    }
    else{
      ti = tt;
      ti -= max(0LL,st[b - 1].fi);
      ti += max(0LL, (hp[ix] * x) - dmg[ix]);
      rez = max(rez,sum + ti);
    }
  }
  cout << rez;
  return 0;
}