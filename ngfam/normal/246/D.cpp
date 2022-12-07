#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N];
set < int > color[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d", &n, &m);
  int answer = N;
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
    answer = min(answer, a[i]);
  }
  for(int i = 1; i <= m; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    if(a[u] == a[v]){
      continue;
    }
    color[a[u]].insert(a[v]);
    color[a[v]].insert(a[u]);
  }
  for(int i = 1; i < N; ++i){
    if(color[i].size() > color[answer].size()){
      answer = i;
    }
  }
  cout << answer;
  return 0;
}