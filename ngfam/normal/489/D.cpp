#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

int n, m;
int same[N][N];
int a[N][N];
pair < int, int > x[N * 10];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    a[u][v] = 1;
    x[i] = make_pair(u, v);
  }
  long long answer = 0;
  for(int i = 1; i <= m; ++i){
    int u = x[i].first, v = x[i].second;
    for(int k = 1; k <= n; ++k){
      if(k == u || k == v){
        continue;
      }
      if(a[v][k] == 1){
        answer += same[u][k];
        ++same[u][k];
      }
    }
  }
  cout << answer;
  return 0;
}