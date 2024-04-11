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
  vector<int> rt;
  int x;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> x;
    rt.push_back(x);
  }
  int l = 0, r = (int)1e9 + 11;
  int md;
  int li, ri;
  bool ok;
  int k = 0;
  while(l < r){
    md = (l + r) / 2;
    li = 0, ri = (int)1e9;
    ok = true;
    for(int i = 1; i < n; i ++ ){
      if(rt[i] != -1 && rt[i - 1] != -1){
        if(abs(rt[i]-rt[i-1]) > md) ok=false;
      }
    }
    for(int i = 0 ; i < n ; i ++ ){
      if(rt[i] != -1){
        if((i > 0 && rt[i - 1] == -1) || (i + 1 < n && rt[i + 1] == -1)){
          li = max(li, rt[i] - md);
          ri = min(ri, rt[i] + md);
        }
      }
    }
    if(li > ri) ok = false;
    if(ok)
      r = md;
    else
      l = md + 1;
  }
  md = r;
  li = 0, ri = (int)1e9;
  for(int i = 0 ; i < n ; i ++ ){
    if(rt[i] != -1){
      if((i > 0 && rt[i - 1] == -1) || (i + 1 < n && rt[i + 1] == -1)){
        li = max(li, rt[i] - md);
        ri = min(ri, rt[i] + md);
      }
    }
  }
  cout << r << " " << li << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int i = 0 ; i < tc; i ++ ){
    solve();
  }
  return 0;
}