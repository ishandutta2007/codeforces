#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
  fastIO;
  int n, m, r, k;
  cin >> n >> m >> r >> k;
  vector<int> pp, qq;
  int li, ri;
  for(int i = 1 ; i <= n; i ++ ){
    li = max(1, i - r + 1);
    ri = min(n - r + 1, i);
    pp.push_back(ri - li + 1);
  }
  for(int i = 1; i <= m; i ++ ){
    li = max(1, i - r + 1);
    ri = min(m - r + 1, i);
    qq.push_back(ri - li + 1);
  }
  sort(pp.begin(), pp.end());
  sort(qq.begin(), qq.end());
  set<pii> cur;
  ld sum = 0;
  ld dv = (n - r + 1) * 1.0 * (m - r + 1);
  priority_queue<pair<ll, pii>> qi;
  qi.push(mp(pp[n - 1] * 1ll * qq[m - 1], mp(n - 1, m - 1)));
  int ii, jj;
  while(!qi.empty()){
    ii = qi.top().se.fi;
    jj = qi.top().se.se;
    qi.pop();
    if(cur.count(mp(ii,jj)) || k <= 0){
      continue;
    }
    cur.insert(mp(ii,jj));
    k -- ;
    sum += pp[ii] * 1.0 * qq[jj];
    if(ii > 0){
      qi.push(mp(pp[ii - 1] * 1ll * qq[jj], mp(ii - 1, jj)));
    }
    if(jj > 0){
      qi.push(mp(pp[ii] * 1ll * qq[jj - 1], mp(ii, jj - 1)));
    }
  }
  cout << fixed << setprecision(15) << sum/dv << "\n";
  return 0; 
}