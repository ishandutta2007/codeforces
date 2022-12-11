#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
ll Cl[N];
ll Cr[N];
int sl[N];
int sr[N];

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0  ; i < n; i ++ )
    cin >> a[i];
  sort(a.begin(), a.end());
  vector<pii> cmp;
  for(int i = 0 ; i < n; i ++ ){
    if(cmp.empty() || a[i] != cmp.back().fi){
      cmp.push_back(mp(a[i], 1));
    }
    else{
      cmp.back().se ++ ;
    }
  }
  int m = cmp.size();
  for(int i = 0 ; i < m; i ++ ){
    if(cmp[i].se >= k){
      cout << "0\n";
      return 0;
    }
  }
  Cl[0]=0;
  sl[0]=cmp[0].se;
  for(int i = 1 ; i < m; i ++ ){
    sl[i] = sl[i-1] + cmp[i].se;
    Cl[i] = Cl[i-1] + (sl[i-1] * 1ll * (cmp[i].fi - cmp[i-1].fi));
  }
  Cr[m-1]=0;
  sr[m-1]=cmp[m-1].se;
  for(int i = m - 2; i >= 0 ; i -- ){
    sr[i] = sr[i + 1] + cmp[i].se;
    Cr[i] = Cr[i+1] + (sr[i+1] * 1ll * (cmp[i+1].fi - cmp[i].fi));
  }
  ll ans = (ll)1e18;
  ll cost;
  for(int i = 1; i + 1 < m; i ++ ){
    cost = Cl[i-1] + Cr[i+1];
    cost += (cmp[i+1].fi-cmp[i].fi-1) * 1ll * sr[i+1];
    cost += (cmp[i].fi-cmp[i-1].fi-1) * 1ll * sl[i-1];
    cost += k - cmp[i].se;
    ans = min(ans, cost);
  }
  for(int i = 1; i < m; i ++ ){
    if(sl[i] >= k){
      cost = Cl[i-1];
      cost += (cmp[i].fi-cmp[i-1].fi-1) * 1ll * sl[i-1];
      cost += k - cmp[i].se;
      ans = min(ans, cost);
    }
  }
  for(int i = m - 2; i >= 0 ; i -- ){
    if(sr[i] >= k){
      cost = Cr[i+1];
      cost += (cmp[i+1].fi-cmp[i].fi-1) * 1ll * sr[i+1];
      cost += k - cmp[i].se;
      ans = min(ans, cost);
      break;
    }
  }
  cout << ans << "\n";
  return 0;
}