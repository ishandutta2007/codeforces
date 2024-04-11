#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int testc;
  cin >> testc;
  for(int tt = 1; tt <= testc; tt ++ ){
    int n;
    cin >> n;
    vector<pii> cc;
    int x, y;
    cc.push_back(mp(0,0));
    for(int i = 0 ; i < n ; i ++ ){
      cin >> x >> y;
      cc.push_back(mp(x,y));
    }
    sort(cc.begin(), cc.end());
    vector<char> ans;
    bool ok = true;
    for(int i = 1; i <= n; i ++ ){
      if(cc[i].fi < cc[i-1].fi || cc[i].se < cc[i-1].se){
        ok = false;
      }
      for(int j = cc[i].fi - cc[i-1].fi; j > 0; j -- ){
        ans.push_back('R');
      }
      for(int j = cc[i].se - cc[i-1].se; j > 0; j -- ){
        ans.push_back('U');
      }
    }
    if(ok){
      cout << "YES\n";
      for(char x : ans)
        cout << x;
      cout << "\n";
    }
    else{
      cout << "NO\n";
    }
  }
  return 0;
}