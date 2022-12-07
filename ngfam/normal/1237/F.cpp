#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3605;
const int mod = 998244353;

int n, h, w;
int c[N][N];
long long f[N][N], g[N][N];
int markc[N], markr[N];

 main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  for(int i = 0; i < N; ++i) {
    c[i][0] = 1;
    for(int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1] * j;
      c[i][j] %= mod;
    }
  }


  cin >> h >> w >> n;
  for(int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    markr[x]++; markc[y]++;

    cin >> x >> y;
    markr[x]++; markc[y]++;
  }

  vector < int > row, col;
  for(int i = 1; i <= h; ++i) {
    if(markr[i] == 0) row.push_back(i);
  }

  for(int i = 1; i <= w; ++i) {
    if(markc[i] == 0) col.push_back(i);
  }

  f[0][0] = 1;
  g[0][0] = 1;


  for(int i = 0; i <= row.size(); ++i) {
    for(int j = 0; j < row.size(); ++j) {
      f[i][j] %= mod;
      f[i + 1][j] += f[i][j];

      if(i + 1 < row.size() && row[i] == row[i + 1] - 1) f[i + 2][j + 1] += f[i][j];
    }
  }


  for(int i = 0; i <= col.size(); ++i) {
    for(int j = 0; j < col.size(); ++j) {
      g[i][j] %= mod;
      g[i + 1][j] += g[i][j];
      if(i + 1 < col.size() && col[i] == col[i + 1] - 1) g[i + 2][j + 1] += g[i][j];
    }
  }

  long long ans = 0;

  for(int tworow = 0; tworow * 2 <= row.size(); ++tworow) {
    for(int twocol = 0; twocol * 2 <= col.size(); ++twocol) {
      long long add = f[row.size()][tworow] * g[col.size()][twocol];
      add %= mod;
      add *= c[col.size() - 2 * twocol][tworow];
      add %= mod;
      add *= c[row.size() - 2 * tworow][twocol];
      add %= mod;
      ans += add;
      ans %= mod;
    }
  }

  cout << ans;

  return 0;
}