#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
  int n, k;
  cin >> n >> k;
  vector<bool> vis(n);
  vector<int> cnt(26);
  char f;
  for(int i = 0 ; i < n; i ++ ){
    cin >> f;
    cnt[f - 'a'] ++ ;
  }
  sort(cnt.begin(), cnt.end());
  int id;
  int ans = 1;
  for(int len = 1; len <= n; len ++ ){
    for(int t = 0; t < len ; t ++ ) vis[t] = false;
    vector<int> szs;
    for(int t = 0; t < len ; t ++ ){
      if(vis[t]) continue;
      id = t;
      int sh = 0;
      while(!vis[id]){
        sh ++ ;
        vis[id]=true;
        id += k;
        id %= len;
      }
      szs.push_back(sh);
    }
    vector<int> cur = cnt;
    sort(szs.begin(), szs.end());
    int low;
    for(int t = szs.size() - 1; t >= 0 ;t -- ){
      for(int j = cur.size() - 1; j >= 0 ; j -- ){
        if(cur[j] >= szs[t]){
          cur[j] -= szs[t];
          szs[t] = 0;
          break;
        }
      }
    }
    bool can = true;
    for(auto x : szs) if(x > 0) can = false;
    if(can) ans = max(ans, len);
  }
  cout << ans << "\n";
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