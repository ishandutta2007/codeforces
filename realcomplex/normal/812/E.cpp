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

const int N = (int)1e5 + 9;
const int M = (1 << 24);

int cnt[2][M];
int dep[N];
vector<int> T[N];
int x[N];

int col = 0;
void dfs(int u){
  cnt[dep[u]][x[u]] ++ ;
  for(auto x : T[u]){
    dep[x] = dep[u] ^ 1;
    dfs(x);
  }
  if(T[u].empty()) col = dep[u];
}

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    cin >> x[i];
  }
  int p;
  for(int i = 2; i <= n; i ++ ){
    cin >> p;
    T[p].push_back(i);
  }
  dfs(1);
  int s = 0;
  for(int i = 1; i <= n; i ++ ){
    if(dep[i] == col){
      s ^= x[i];
    }
  }
  ll ans = 0;
  if(s == 0){
    for(int i = 0 ; i < M ; i ++ ){
      ans += cnt[0][i] * 1ll * cnt[1][i];
    }
    ll c0 = 0, c1 = 0;
    for(int i = 1; i <= n; i ++ ){
      if(dep[i] == 0) c0 ++ ;
      else c1 ++ ;
    }
    ans += c0 * 1ll * (c0 - 1) / 2ll;
    ans += c1 * 1ll * (c1 - 1) / 2ll;
  }
  else{
    for(int i = 0 ; i < M ; i ++ ){
      ans += cnt[0][i] * 1ll * cnt[1][(s ^ i)];
    }
  }
  cout << ans << "\n";
  return 0;
}