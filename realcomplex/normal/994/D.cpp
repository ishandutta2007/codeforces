#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int n,m;
vector<pii> ff, ss;

bool valid(pii A, pii B){
  if(A == B)
    return false;
  if(A.fi == B.fi)
    return true;
  if(A.fi == B.se)
    return true;
  if(A.se == B.se)
    return true;
  if(A.se == B.fi)
    return true;
  return false;
}

int you(){
  int cnt = 0;
  int xx = -1;
  bool ok;
  for(int i = 1;i <= 9;i ++ ){
    ok = false;
    for(int j = 0;j < n; j ++ ){
      for(int x = 0;x < m; x ++ ){
        if(ff[j] == ss[x])
          continue;
        if((ff[j].fi == i or ff[j].se == i) and (ss[x].fi == i or ss[x].se == i)){
          ok = true;
        }
      }
    }
    if(ok)
      cnt ++, xx = i;
  }
  if(cnt == 1)
    return xx;
  return -1;
}

bool what(){
  bool v1, v2;
  for(int i = 0;i < n;i ++ ){
    v1 = false;
    v2 = false;
    for(int j = 0;j < m;j ++ ){
      if(ff[i] == ss[j])
        continue;
      if(ff[i].fi == ss[j].fi or ff[i].fi == ss[j].se)
        v1 = true;
      if(ff[i].se == ss[j].fi or ff[i].se == ss[j].se)
        v2 = true;
    }
    if(v1 == true and v2 == true){
      return false;
    }
  }
  return true;
}

int main(){
  fastIO;
  cin >> n >> m;
  pii cur;
  for(int i = 0;i < n;i ++ ){
    cin >> cur.fi >> cur.se;
    if(cur.fi > cur.se)
      swap(cur.fi, cur.se);
    ff.push_back(cur);
  }
  for(int i = 0;i < m;i ++ ){
    cin >> cur.fi >> cur.se;
    if(cur.fi > cur.se)
      swap(cur.fi, cur.se);
    ss.push_back(cur);
  }
  int ans = you();
  if(ans != -1){
    cout << ans;
    return 0;
  }
  bool p1 = what();
  swap(n,m);
  swap(ff, ss);
  bool p2 = what();
  if(p1 == true and p2 == true){
    cout << 0;
  }
  else{
    cout << -1;
  }
  return 0;
}