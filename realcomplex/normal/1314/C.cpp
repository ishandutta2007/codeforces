#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1010;
const int T = (int)1e6 + 10;
const int AL = 26;
const ll inf = (ll)1e18 + 150;

int nx[T][AL];
int id[T];
int cnt = 1;
char pi[N];

vector<int> lis;

void dfs(int u){
  if(u > 0){
    id[u]=lis.size();
    lis.push_back(u);
  }
  for(int j = 0 ; j < AL; j ++ ){
    if(nx[u][j] != -1) dfs(nx[u][j]);
  }
}

int lc[N];
ll dp[N][N];

void add(ll &a, ll b){
  a = min(inf, a + b);
}

int main(){
  fastIO;
  int n, m;
  ll k;
  cin >> n >> m >> k;
  for(int i = 0 ; i < T; i ++ ){
    for(int j = 0 ; j < AL ; j ++ ){
      nx[i][j]=-1;
    }
  }
  for(int i = 1; i <= n; i ++ ){
    cin >> pi[i];
  }
  int node;
  for(int i = 1; i <= n; i ++ ){
    node = 0;
    for(int j = i ; j <= n; j ++ ){
      if(nx[node][pi[j] - 'a'] == -1){
        nx[node][pi[j] - 'a'] = cnt ++ ;
      }
      node = nx[node][pi[j] - 'a'];
    }
  }
  dfs(0);
  int lef = 0, rig = (int)lis.size();
  int mid;
  while(lef + 1 < rig){
    mid = (lef + rig) / 2;
    for(int i = 1 ; i <= n; i ++ ){
      lc[i] = -1;
      node = 0;
      for(int j = i ; j <= n; j ++ ){
        node=nx[node][pi[j] - 'a'];
        if(id[node]>=mid){
          lc[i]=j;
          break;
        }
      }
    }
    for(int i = 1 ; i <= n + 1; i ++ ){
      for(int j = 0 ; j <= m ; j ++ ){
        dp[i][j]=0;
      }
    }
    for(int i = 1; i <= n + 1; i ++ ){
      dp[i][0]=1;
    }
    for(int j = 1; j <= m; j ++ ){
      for(int i = n; i >= 1; i -- ){
        if(lc[i] != -1){
          add(dp[i][j],dp[lc[i] + 1][j - 1]);
        }
      }
      if(j < m)
        for(int i = n; i >= 1; i -- )
          add(dp[i][j], dp[i + 1][j]);
    }
    if(dp[1][m] >= k)
      lef = mid;
    else
      rig = mid;
  }
  node = 0;
  for(int i = 1; i <= n; i ++ ){
    node = 0;
    for(int j = i ; j <= n; j ++ ){
      node = nx[node][pi[j] - 'a'];
      if(id[node] == lef){
        for(int k = i ; k <= j ; k ++ ){
          cout << pi[k];
        }
        cout << "\n";
        return 0;
      }
    }
  }
  return 0;
}