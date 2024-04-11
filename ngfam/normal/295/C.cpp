#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int mod = 1e9 + 7;

typedef pair < int, pair < pair < int, int >, int > > ii;

int n, k;
int a[N];
int c[N][N];
int f[N][N][2];
int done[N][N][2];
int path[N][N][2];

bool minimize(int &u, int v){
  if(u > v){
    u = v;
    return true;
  }
  return false;
}

void add(int &u, int v){
  u += v;
  if(u >= mod){
    u -= mod;
  }
}

int mul(int u, int v){
  return (1LL * u * v) % mod;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  int five = 0, ten = 0;
  for(int i = 1; i <= n; ++i){
    if(a[i] == 50){
      ++five;
    }
    else{
      ++ten;
    }
  }
  c[0][0] = 1;
  for(int i = 1; i <= n; ++i){
    c[i][0] = 1;
    for(int j = 1; j <= i; ++j){
      c[i][j] = c[i - 1][j];
      add(c[i][j], c[i - 1][j - 1]);
    }
  }
  memset(path, 60, sizeof path);
  path[five][ten][0] = 0;
  f[five][ten][0] = 1;
  priority_queue < ii, vector < ii >, greater < ii > > heap;
  heap.push(ii(0, make_pair(make_pair(five, ten), 0)));
  while(!heap.empty()){
    int x = heap.top().second.first.first;
    int y = heap.top().second.first.second;
    int z = heap.top().second.second;
    heap.pop();
    if(done[x][y][z] == 1){
      continue;
    }
    done[x][y][z] = 1;
    if(z == 0){
      for(int t = 0; t <= x; ++t){
        for(int d = 0; d <= y; ++d){
          if(50 * t + 100 * d > k){
            break;
          }
          if(t == 0 && d == 0){
            continue;
          }
          int ways = mul(f[x][y][z], mul(c[x][t], c[y][d]));
          if(minimize(path[x - t][y - d][1], path[x][y][z] + 1)){
            f[x - t][y - d][1] = ways;
            heap.push(make_pair(path[x - t][y - d][1], make_pair(make_pair(x - t, y - d), 1)));
          }
          else if(path[x - t][y - d][1] == path[x][y][z] + 1){
            add(f[x - t][y - d][1], ways);
          }
        }
      }
    }
    else{
      for(int d = 0; d <= five - x; ++d){
        for(int t = 0; t <= ten - y; ++t){
          if(100 * t + 50 * d > k){
            break;
          }
          if(t == 0 && d == 0){
            continue;
          }
          int ways = mul(f[x][y][z], mul(c[five - x][d], c[ten - y][t]));
          if(minimize(path[x + d][y + t][0], path[x][y][z] + 1)){
            f[x + d][y + t][0] = ways;
            heap.push(make_pair(path[x + d][y + t][0], make_pair(make_pair(x + d, y + t), 0)));
          }
          else{
            add(f[x + d][y + t][0], ways);
          }
        }
      }
    }
  }
  if(path[0][0][1] == path[n + 1][0][0]){
    puts("-1");
    puts("0");
  }
  else{
    printf("%d\n%d", path[0][0][1], f[0][0][1]);
  }
  return 0;
}