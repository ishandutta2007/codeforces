#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int f[N][30][2];
int n;
int arr[N];
long long answer;
vector < int > adj[N];

void dfs(int u, int p){
  for(int i = 0; i < 20; ++i){
    if(arr[u] & (1 << i)){
      ++f[u][i][1];
    }
    else{
      ++f[u][i][0];
    }
  }
  for(int v : adj[u]){
    if(v == p){
      continue;
    }
    dfs(v, u);
    for(int i = 0; i < 20; ++i){
      answer += (1LL << i) * f[u][i][0] * f[v][i][1];
      answer += (1LL << i) * f[u][i][1] * f[v][i][0];
    }
    for(int i = 0; i < 20; ++i){
      int values;
      values = ((((1 << i) ^ (arr[u])) & (1 << i)) > 0);
      f[u][i][values] += f[v][i][1];
      values = ((arr[u] & (1 << i)) > 0);
      f[u][i][values] += f[v][i][0];
//      cerr << i << " " << v << " " << f[v][i][1] << endl;
    }
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", arr + i);
    answer += arr[i];
  }
  for(int i = 1; i < n; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  cout << answer;
  return 0;
}