#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, k, p;
int a[N][N];
long long col[N];
long long row[N];
long long frow[N * N];
long long fcol[N * N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d%d%d", &n, &m, &k, &p);
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[i][j]);
    }
  }
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      row[i] += a[i][j];
      col[j] += a[i][j];
    }
  }
  priority_queue < long long > pq;
  for(int i = 1; i <= n; ++i){
    pq.push(row[i]);
  }
  for(int i = 1; i <= k; ++i){
    frow[i] = frow[i - 1] + pq.top();
    long long x = pq.top();
    pq.pop();
    pq.push(x - 1LL * m * p);
  }
  while(!pq.empty()){
    pq.pop();
  }
  for(int i = 1; i <= m; ++i){
    pq.push(col[i]);
  }
  for(int i = 1; i <= k; ++i){
    fcol[i] = fcol[i - 1] + pq.top();
    long long x = pq.top();
    pq.pop();
    pq.push(x - 1LL * n * p);
  }
  long long answer = -1e18;
  for(int i = 0; i <= k; ++i){
    answer = max(answer, frow[i] + fcol[k - i] - 1LL * i * 1LL * (k - i) * p);
  }
  cout << answer;
  return 0;
}