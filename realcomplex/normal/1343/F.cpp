#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 205;
set<int> R[N];
int n;
int cnt[N];

vector<int> att(vector<int> per){
  for(int i = 0 ; i <= n; i ++ ) cnt[i] = 0;
  for(auto x : per){
    for(int i = 2; i <= n; i ++ ){
      if(R[i].count(x)) cnt[i] ++ ;
    }
  }
  int id;
  int p;
  int nx;
  set<int> las;
  for(int i = 3; i <= n; i ++ ){
    id = -1;
    for(int j = 2; j <= n ; j ++ ){
      if(cnt[j] == R[j].size() - 1){
        if(id == -1) id = j;
        else{
          return {};
        }
      }
    }
    if(id == -1) return {};
    p = per.size();
    nx = -1;
    las.clear();
    for(int j = 0 ; j < cnt[id];  j ++ ){
      p -- ;
      if(!R[id].count(per[p])) return {};
      las.insert(per[p]);
    }
    for(auto x : R[id]){
      if(!las.count(x)) nx = x;
    }
    for(int j = 2; j <= n; j ++ ){
      if(R[j].count(nx)) cnt[j] ++ ;
    }
    per.push_back(nx);
  }
  return per;
}

void solve(){
  cin >> n;
  for(int i = 0 ; i <= n; i ++ ) {
    R[i].clear();
  }
  int k, x;
  for(int i = 2; i <= n; i ++ ){
    cin >> k;
    for(int j = 0 ; j < k ; j ++ ){
      cin >> x;
      R[i].insert(x);
    }
  }
  vector<int> ans;
  for(int i = 2; i <= n; i ++ ){
    if(R[i].size() == 2){
      auto it = R[i].begin();
      auto nx = it;
      nx ++ ;
      ans = att({*it, *nx});
      if(!ans.empty()){
        for(auto p : ans) cout << p << " ";
        cout << "\n";
        return;
      }
      ans = att({*nx, *it});
      if(!ans.empty()){
        for(auto p : ans) cout << p << " ";
        cout << "\n";
        return;
      }
    }
  }
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i ++ ){
    solve();
  }
  return 0;
}