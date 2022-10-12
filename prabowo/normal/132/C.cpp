#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int dp[105][55][2];
bool vis[105][55][2];
int f(int x, int y, int dir) {
  if (y < 0) return -1000000000;
  if (x == s.size()) return (y & 1 ? -1000000000 : 0);
  if (vis[x][y][dir]) return dp[x][y][dir];
  vis[x][y][dir] = true;
  
  int ret;
  int step = (dir == 0 ? -1 : 1);
  if (s[x] == 'T') {
    ret = max(f(x+1, y, dir ^ 1), f(x+1, y-1, dir) + step);
  } else {
    ret = max(f(x+1, y, dir) + step, f(x+1, y-1, dir ^ 1));
  }
  return dp[x][y][dir] = ret;
}

int dp2[105][55][2];
bool vis2[105][55][2];
int f2(int x, int y, int dir) {
  if (y < 0) return 1000000000;
  if (x == s.size()) return (y & 1 ? 1000000000 : 0);
  if (vis2[x][y][dir]) return dp2[x][y][dir];
  vis2[x][y][dir] = true;
  
  int ret;
  int step = (dir == 0 ? -1 : 1);
  if (s[x] == 'T') {
    ret = min(f2(x+1, y, dir ^ 1), f2(x+1, y-1, dir) + step);
  } else {
    ret = min(f2(x+1, y, dir) + step, f2(x+1, y-1, dir ^ 1));
  }
  return dp2[x][y][dir] = ret;
}

int solve() {
  cin >> s;
  scanf("%d", &n);
  memset(vis, false, sizeof vis);
  memset(vis2, false, sizeof vis2);

  // cerr << f(0, n, 1) << endl;
  // cerr << f2(0, n, 1) << endl;

  int res = max(f(0, n, 1), -f2(0, n, 1));
  printf("%d\n", res);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}