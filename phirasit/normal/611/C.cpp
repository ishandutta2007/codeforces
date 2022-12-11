#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;

int sum[N][N], ver[N][N], hor[N][N];
string str[N];
int h, w, q;

int main() {
  ios::sync_with_stdio(false);
  cin >> h >> w;
  for(int i = 0;i < h;i++) {
    cin >> str[i];
  }
  for(int i = 0;i < h;i++) {
    hor[i][0] = 0;
    for(int j = 1;j < w;j++) {
      hor[i][j] = hor[i][j-1] + (str[i][j-1] == '.' and str[i][j] == '.');
    }
  }
  for(int j = 0;j < w;j++) {
    ver[0][j] = 0;
    for(int i = 1;i < h;i++) {
      ver[i][j] = ver[i-1][j] + (str[i-1][j] == '.' and str[i][j] == '.');
    }
  }
  for(int i = 0;i < h;i++) {
    for(int j = 0;j < w;j++) {
      sum[i][j] = 0;
      if(i > 0) sum[i][j] += sum[i-1][j] + (str[i-1][j] == '.' and str[i][j] == '.');
      if(j > 0) sum[i][j] += sum[i][j-1] + (str[i][j-1] == '.' and str[i][j] == '.');
      if(i > 0 and j > 0) sum[i][j] -= sum[i-1][j-1];
    }
  }

  cin >> q;
  while(q--) {
    int r1, r2, c1, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, r2--, c1--, c2--;
    int ans = sum[r2][c2] - sum[r1][c2] - sum[r2][c1] + sum[r1][c1];
    ans += ver[r2][c1] - ver[r1][c1];
    ans += hor[r1][c2] - hor[r1][c1];
    cout << ans << endl;
  }

  return 0;
}