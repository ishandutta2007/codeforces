#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
int a[N][N];
char s[N][N];
int f[N][N][N][N];

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> (s[i] + 1);
    for(int j = 1; j <= n; ++j) {
      a[i][j] = (s[i][j] == '#'); 
    }
  }

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }

  for(int lenx = 1; lenx <= n; ++lenx) {
    for(int leny = 1; leny <= n; ++leny) {
      for(int x = 1; x + lenx - 1 <= n; ++x) {
        for(int y = 1; y + leny - 1 <= n; ++y) {
          int u = x + lenx - 1, v = y + leny - 1;
          int cnt = a[u][v] - a[u][y - 1] - a[x - 1][v] + a[x - 1][y - 1];
          if(cnt == 0) {
            f[x][y][u][v] = 0;
            continue;
          }

          f[x][y][u][v] = max(u - x + 1, v - y + 1); 

          int &val = f[x][y][u][v];
          for(int k = x; k < u; ++k) {
            val = min(val, f[x][y][k][v] + f[k + 1][y][u][v]);
          }
          for(int k = y; k < v; ++k) {
            val = min(val, f[x][y][u][k] + f[x][k + 1][u][v]);
          }
          //cout << x << " " << y << " " << u << " " << v << " " << val << endl;
        }
      }
    }
  }

  cout << f[1][1][n][n];

  return 0;
}