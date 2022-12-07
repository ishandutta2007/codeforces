#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2020;
const int mod = 1e9 + 7;
 
int n, m;
char a[N][N];
 
int f[N][N][2];
 
int toright[N][N];
int todown[N][N];
 
void fix(int &x) {
  x %= mod;
  if(x < 0) x += mod;
}
 
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
 
  cin >> n >> m;
 
  if(n == 1 && m == 1) {
    cout << 1 << endl;
    return 0;
  }
  for(int i = 1; i <= n; ++i) {
    cin >> (a[i] + 1);
  }
 
  for(int i = n; i >= 1; --i) {
    for(int j = m; j >= 1; --j) {
      toright[i][j] = toright[i][j + 1] + (a[i][j] == 'R');
      todown[i][j] = todown[i + 1][j] + (a[i][j] == 'R');
    }
  }
 
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(i == 1 && j == 1) {
        int w = m - toright[i][j + 1];
        int h = n - todown[i + 1][j];
        f[i][j + 1][0]++;
        f[i][w + 1][0]--;
        f[i + 1][j][1]++;
        f[h + 1][j][1]--;
      }
      else {
        f[i][j][0] += f[i][j - 1][0];
        f[i][j][1] += f[i - 1][j][1];
        fix(f[i][j][0]);
        fix(f[i][j][1]);
        int w = m - toright[i][j + 1];
        int h = n - todown[i + 1][j];
        f[i][j + 1][0] += f[i][j][1];
        f[i][w + 1][0] -= f[i][j][1];
        f[i + 1][j][1] += f[i][j][0];
        f[h + 1][j][1] -= f[i][j][0];
        fix(f[i][j + 1][0]);
        fix(f[i][w + 1][0]);
        fix(f[i + 1][j][1]);
        fix(f[h + 1][j][1]);
      }
    }
  }
 
 
  int ans = f[n][m][0] + f[n][m][1];
  fix(ans);
  cout << ans << endl;
 
  return 0;
}