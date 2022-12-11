#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e7 + 9;
int nx[N][2];
int dp[N];
int cnt;

void dfs(int u,int dep){
  if(nx[u][0] == -1 && nx[u][1] == -1){
    dp[u] = 0;
    return;
  }
  if(nx[u][1] == -1){
    dfs(nx[u][0],dep-1);
    dp[u]=dp[nx[u][0]];
  }
  else if(nx[u][0] == -1){
    dfs(nx[u][1],dep-1);
    dp[u]=dp[nx[u][1]];
  }
  else{
    dfs(nx[u][0],dep-1);
    dfs(nx[u][1],dep-1);
    dp[u]=min(dp[nx[u][0]],dp[nx[u][1]])+(1<<dep);
  }
}

int main(){
  fastIO;
  for(int i = 0 ; i < N ; i ++ )
    nx[i][0] = nx[i][1] = -1;
  int n;
  cin >> n;
  int a;
  int cur;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> a;
    cur = 0;
    for(int j = 29;j >= 0 ; j -- ){
      if(a & (1 << j)){
        if(nx[cur][1] == -1)
          nx[cur][1] = ++cnt;
        cur=nx[cur][1];
      }
      else{
        if(nx[cur][0] == -1)
          nx[cur][0] = ++cnt;
        cur=nx[cur][0];
      }
    }
  }
  dfs(0,29);
  cout << dp[0] << "\n";
  return 0;
}