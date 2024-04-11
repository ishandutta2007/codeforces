#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

pii res[10000];


int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  vector<int> t;
  int ans = -1;
  int cur;
  for(int i = 0 ; i < n ; i ++ ){
    t.clear();
    t.resize(m);
    for(int j = 0 ; j < m ; j ++ ){
      cin >> t[j];
    }
    for(int x = 0; x < (1 << m); x ++ ){
      cur = (int)1e9 + 9;
      for(int p = 0; p < m ; p ++ ){
        if(x & (1 << p)){
          cur = min(cur, t[p]);
        }
      }
      res[x] = max(res[x], mp(cur,i+1));
    }
  }
  int ii=-1, jj=-1;
  for(int x = 0; x < (1 << m); x ++ ){
    if(ans < min(res[x].fi,res[(1<<m)-1-x].fi)){
      ans = min(res[x].fi, res[(1<<m)-1-x].fi);
      ii = res[x].se;
      jj = res[(1<<m)-1-x].se;
    }
  }
  cout << ii << " " << jj << "\n";
  return 0;
}