#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  string t;
  cin >> t;
  int n = t.size();
  vector<bool> bad(n, false);
  for(int i = 0 ; i + 4 < n; i ++ ){
    if(t[i] == 't' && t[i + 1] == 'w' && t[i + 2] == 'o' && t[i + 3] == 'n' && t[i + 4] == 'e'){
      t[i + 2] = '#';
      bad[i + 2] = true;
    }
  }
  for(int i = 0 ; i + 2 < n; i ++ ){
    if(t[i] == 'o' && t[i + 1] == 'n' && t[i + 2] == 'e'){
      t[i + 1] = '#';
      bad[i + 1] = true;
    }
    if(t[i] == 't' && t[i + 1] == 'w' && t[i + 2] == 'o'){
      t[i + 1] = '#';
      bad[i + 1] = true;
    }
  }
  vector<int> ans;
  for(int i = 0 ;i < n; i ++ ){
    if(bad[i])
      ans.push_back(i + 1);
  }
  cout << ans.size() << "\n";
  for(auto x : ans)
    cout << x << " ";
  cout << "\n";
}

int main(){
  fastIO;
  int q;
  cin >> q;
  for(int t = 0; t < q; t ++ ){
    solve();
  }
  return 0;
}