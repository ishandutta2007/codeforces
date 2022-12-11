#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
vector<int> T[N];
int subt[N];
int dep[N];

int c;

vector<int> good;

void dfs(int u, int par){
  subt[u] = 1;
  for(auto x : T[u]){
    if(x == par) continue;
    dep[x] = dep[u] + 1;
    dfs(x, u);
    subt[u] += subt[x];
  }
  good.push_back(subt[u]-dep[u] - 1);
}

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  c = n - k;
  int u, v;
  for(int i = 1; i < n; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  dfs(1, -1);
  sort(good.begin(), good.end());
  reverse(good.begin(),good.end());
  ll ans = 0;
  for(int i = 0 ; i < c; i ++ ){
    ans += good[i];
  }
  cout << ans << "\n";
  return 0;
}