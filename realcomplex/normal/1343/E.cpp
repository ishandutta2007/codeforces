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

const int N = (int)2e5 + 9;
const ll inf = (ll)1e15;
ll p[N];
vector<int> T[N];
int d[3][N];
int y;
int n;

void bfs(int u){
  for(int i = 1; i <= n; i ++ )
    d[y][i] = n + 512;
  queue<int> bf;
  bf.push(u);
  d[y][u] = 0;
  while(!bf.empty()){
    u = bf.front();
    bf.pop();
    for(auto x : T[u]){
      if(d[y][u] + 1 < d[y][x]){
        d[y][x] = d[y][u] + 1;
        bf.push(x);
      }
    }
  }
  y ++ ;
}

void solve(){
  int m, a, b, c;
  cin >> n >> m >> a >> b >> c;
  for(int i = 1; i <= n; i ++ )
    T[i].clear();
  y = 0;
  for(int i = 1; i <= m ; i ++ ){
    cin >> p[i];
  }
  int u, v;
  for(int i = 1; i <= m ; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  sort(p + 1, p + 1 + m);
  bfs(a);
  bfs(b);
  bfs(c);
  for(int i = 1; i <= m; i ++ ){
    p[i] += p[i - 1];
  }
  int tot;
  ll ans = inf;
  for(int i = 1; i <= n; i ++ ){
    tot = d[0][i] + d[1][i] + d[2][i];
    if(tot > m) continue;
    ans = min(ans, p[tot] + p[d[1][i]]);
  }
  cout << ans << "\n";
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