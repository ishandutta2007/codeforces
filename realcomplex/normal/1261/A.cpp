#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  int n, k;
  cin >> n >> k;
  vector<char> t(n);
  for(int i = 0 ; i < n ; i ++ )
    cin >> t[i];
  vector<pii> res;
  int cnt = 0;
  for(int j = 0 ; j < k - 1; j ++ ){
    for(int i = 2 * j; i < n; i ++ ){
      if(t[i] == '('){
        if(2 * j == i) break;
        res.push_back(mp(2 * j,i));
        reverse(t.begin() + 2 * j, t.begin() + i + 1);
        break;
      }
    }
    for(int i = 2 * j + 1; i < n; i ++ ){
      if(t[i] == ')'){
        if(2 * j + 1 == i) break;
        res.push_back(mp(2 * j + 1,i));
        reverse(t.begin() + 2 * j + 1, t.begin() + i + 1);
        break;
      }
    }
  }
  int p = 2 * (k - 1);
  for(int j = 2 * (k - 1); j < n; j ++ ){
    if(t[j] == '('){
      res.push_back(mp(p,j));
      reverse(t.begin() + p, t.begin() + j + 1);
      p ++ ;
    }
  }
  cout << res.size() << "\n";
  for(auto x : res)
    cout << x.fi + 1 << " " << x.se + 1 << "\n";
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