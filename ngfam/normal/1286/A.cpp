#include<bits/stdc++.h>

using namespace std;

const int MAXN = 110;

int n;
int a[MAXN];
int f[MAXN][MAXN][MAXN][2];

void umin(int &x, int y) {
  x = min(x, y);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  int odd = (n + 1) / 2, even = n - odd;

  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    if(a[i] != 0) {
      if(a[i] % 2 == 1) --odd;
      else --even;
    }
  }

  memset(f, 60, sizeof f);
  f[0][0][0][0] = 0;
  f[0][0][0][1] = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j <= odd; ++j) {
      for(int k = 0; k <= even; ++k) {
        for(int last = 0; last < 3; ++last) {
          int x = a[i];
          if(x != 0) {
            umin(f[i + 1][j][k][x % 2], f[i][j][k][last] + (last != x % 2));
          }
          else {
            if(j < odd) umin(f[i + 1][j + 1][k][1], f[i][j][k][last] + (last != 1));
            if(k < even) umin(f[i + 1][j][k + 1][0], f[i][j][k][last] + (last != 0));
          }
        }
      }
    }
  }


  cout << min(f[n][odd][even][0], f[n][odd][even][1]) << endl;

  return 0;
}