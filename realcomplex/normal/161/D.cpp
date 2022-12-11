#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

const int N = (int)5e4 + 9;
const int K = 511;

vector<int>T[N];
int dp[N][K];

int k;
ll ans = 0;

void dfs(int u, int par){
  dp[u][0] = 1;
  for(auto i : T[u]){
    if(i == par)
      continue;
    dfs(i, u);
    for(int j = 0; j < k;j ++ )
      ans += 1ll * dp[i][j] * dp[u][k - j - 1];
    for(int j = 0; j < k;j ++ )
      dp[u][j + 1] += dp[i][j];
  }
}

int main(){
  fastIO;
  int n;
  cin >> n >> k;
  int u, v;
  for(int i = 1;i < n;i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  dfs(1, -1);
  cout << ans;
  return 0;
}