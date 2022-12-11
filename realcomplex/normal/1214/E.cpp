#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<pii> els;
  int a;
  for(int i = 1;  i <= n; i ++ ){
    cin >> a;
    els.push_back(mp(a, i));
  }
  sort(els.begin(), els.end());
  reverse(els.begin(), els.end());
  vector<int> ord;
  for(auto p : els){
    ord.push_back(p.se * 2 - 1);
  }
  int idx = 0;
  vector<pii> answ;
  for(auto p : els){
    if(idx + p.fi == (int)ord.size()){
      ord.push_back(p.se * 2);
    }
    else if(idx + p.fi > (int)ord.size()){
      cout << "Oh shit, here we go again.\n";
      return 0;
    }
    else{
      answ.push_back(mp(ord[idx + p.fi - 1], p.se * 2));
    }
    idx ++ ;
  }
  for(int i = 1; i < ord.size(); i ++ ){
    answ.push_back(mp(ord[i-1], ord[i]));
  }
  for(auto p : answ)
    cout << p.fi << " " << p.se << "\n";
  return 0;
}