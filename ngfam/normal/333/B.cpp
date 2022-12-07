#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
int a[N][N];
int row[N];
int col[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    row[x] = 1;
    col[y] = 1;
  }
  int answer = 0;
  for(int i = 2; i < n; ++i){
    answer += (row[i] == 0) + (col[i] == 0);
  }
  if(n % 2 == 1){
    int x = (n + 1) / 2;
    if(row[x] == 0){
      --answer;
    }
    if(col[x] == 0){
      --answer;
    }
    if(row[x] == 0 || col[x] == 0){
      ++answer;
    }
  }
  cout << answer;
  return 0;
}