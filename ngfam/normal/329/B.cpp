#include <bits/stdc++.h>

using namespace std;

const int N = 3010, M = 1000;

int n, m;
int f[N][N];
char a[N][N];
int arr[N][N];
int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
   // freopen("1.out", "w", stdout);
  #endif // pts
  int stx = 0, sty = 0;
  int fnx = 0, fny = 0;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%s", a[i] + 1);
    for(int j = 1; j <= m; ++j){
      if(a[i][j] == 'E'){
        stx = i;
        sty = j;
      }
      if(a[i][j] == 'S'){
        fnx = i;
        fny = j;
      }
    }
  }
  queue < pair < int, int > > bfs;
  f[stx][sty] = 1;
  bfs.push(make_pair(stx, sty));
  while(!bfs.empty()){
    int u = bfs.front().first;
    int v = bfs.front().second;
    bfs.pop();
    for(int d = 0; d < 4; ++d){
      int x = u + dirx[d];
      int y = v + diry[d];
      if(x < 1 || x > n || y < 1 || y > m){
        continue;
      }
      if(a[x][y] == 'T'){
        continue;
      }
      if(f[x][y] != 0){
        continue;
      }
      f[x][y] = f[u][v] + 1;
      bfs.push(make_pair(x, y));
    }
  }
  int answer = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(isdigit(a[i][j]) && f[i][j] <= f[fnx][fny] && f[i][j] > 0){
        answer += a[i][j] - '0';
      }
    }
  }
  cout << answer;
  return 0;
}