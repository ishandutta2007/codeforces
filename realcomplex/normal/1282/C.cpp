#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){ 
  int n, t;
  ll a, b;
  cin >> n >> t >> a >> b;
  vector<int> f(n);
  for(int i = 0 ; i < n; i ++ )
    cin >> f[i];
  vector<pii> mn;
  int s;
  vector<int> lv;
  int res =0 ;
  lv.push_back(t);
  for(int i =0 ; i < n; i ++ ){
    cin >> s;
    if(s>0)lv.push_back(s-1);
    mn.push_back(mp(s, f[i]));
  }
  sort(lv.begin(), lv.end());
  lv.resize(unique(lv.begin(), lv.end()) - lv.begin());
  sort(mn.begin(), mn.end());
  int p = 0;
  ll ca = 0, cb = 0;
  ll oa = 0, ob = 0;
  for(int p = 0 ; p < mn.size(); p ++ ){
    if(mn[p].se == 0) oa ++ ;
    else ob ++ ;
  }
  ll rem;
  int ret =0 ;
  ll k;
  for(int i = 0; i < lv.size(); i ++ ){
    while(p < mn.size() && mn[p].fi <= lv[i]){
      if(mn[p].se == 0) ca ++, oa -- ;
      else cb ++, ob --  ;
      p ++ ;
    }
    if(ca * a + cb * b <= lv[i]){
      ret = p;
      rem = lv[i] - ca * a - cb * b;
      k = min(rem/a, oa);
      rem -= k * a;
      ret += k;
      k = min(rem/b, ob);
      ret += k;
      res = max(res, ret);
    }
  }
  cout << res << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ; t < tc; t ++ ){
    solve();
  }
  return 0;
}