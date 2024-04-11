#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  int n;
  cin >> n;
  vector<int> cur;
  int x;
  int m;
  for(int i = 0 ; i < n; i ++ ){
    cin >> x;
    if(cur.size() <= 1){
      cur.push_back(x);
    }
    else{
      m = cur.size();
      if(cur[m - 2] >= cur[m - 1] && cur[m - 1] >= x){
        cur.pop_back();
      }
      if(cur[m - 2] <= cur[m - 1] && cur[m - 1] <= x){
        cur.pop_back();
      }
    }
    cur.push_back(x);
  }
  cout << cur.size() << "\n";
  for(auto x : cur) cout << x << " ";
  cout << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc ; t ++ ){
    solve();
  }
  return 0;
}