#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)3e5 + 9;
int id[N];
set<int> T[N];
int idx[N];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  vector<pair<vector<int>, int>> pp;
  vector<int> emp;
  for(int i = 0 ; i < n; i ++ ){
    emp = {i};
    pp.push_back(mp(emp,i));
  }
  int u, v;
  vector<pii> ee;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> u >> v;
    u--;
    v--;
    ee.push_back(mp(u, v));
    pp[u].fi.push_back(v);
    pp[v].fi.push_back(u);
  }
  for(int i = 0 ; i < n; i ++ ){
    sort(pp[i].fi.begin(), pp[i].fi.end());
  }
  sort(pp.begin(), pp.end());
  int cnt = 0;
  for(int i = 0 ; i < pp.size(); i ++ ){
    if(i == 0){
      id[pp[i].se] = cnt;
    }
    else{
      if(pp[i].fi == pp[i-1].fi){
        id[pp[i].se] = cnt;
      }
      else{
        id[pp[i].se] = ++cnt;
      }
    }
  }
  for(auto x : ee){
    if(id[x.fi] != id[x.se]){
      T[id[x.fi]].insert(id[x.se]);
      T[id[x.se]].insert(id[x.fi]);
    }
  }
  if(cnt == 0){
    cout << "YES\n";
    for(int i = 1; i <= n; i ++ )
      cout << 1 << " ";
    return 0;
  }
  for(int i = 0; i <= cnt; i ++ ){
    if(T[i].size() > 2){
      cout << "NO\n";
      return 0;
    }
    idx[i] = -1;
  }
  int p;
  bool can;
  int nd;
  for(int i = 0 ; i <= cnt; i ++ ){
    if(T[i].size() == 1){
      p = 0;
      can=true;
      nd = i;
      while(can){
        can = false;
        p ++ ;
        idx[nd] = p;
        for(auto x : T[nd]){
          if(idx[x] != -1) continue;
          nd = x;
          can = true;
        }
      }
      cout << "YES\n";
      for(int j = 0; j < n; j ++ ){
        cout << idx[id[j]] << " ";
      }
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}