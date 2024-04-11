#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;
vector<int> T[N];
set<int> idx[N];
int col[N];

void dfs(int u, int par){
  set<int> f;
  for(auto p : idx[u]){
    if(col[p] != 0)f.insert(col[p]);
  }
  int pp = 1;
  for(auto p : idx[u]){
    if(col[p] != 0) continue;
    while(f.count(pp)) pp ++ ;
    f.insert(pp);
    col[p] = pp;
  }
  for(auto x : T[u]){
    if(x==par) continue;
    dfs(x, u);
  }
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int k, a, u, v;
  for(int i = 1 ;i <= n; i ++ ){
    cin >> k;
    for(int j = 0 ; j < k ; j ++ ){
      cin >> a;
      idx[i].insert(a);
    }
  }
  for(int i = 1; i < n; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  dfs(1, 0);
  int res = 0;
  for(int i = 1; i <= m; i ++ ){
    if(col[i] == 0)
      col[i] = 1;
    res = max(res, col[i]);
  }
  cout << res << "\n";
  for(int i = 1; i <= m ; i ++ )
    cout << col[i] << " ";
  cout << "\n";
  return 0;
}