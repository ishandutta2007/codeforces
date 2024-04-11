#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;
char s[N][N];

vector<vector<int>> ans;

void apply(int x, int y, int k) {
  vector<int> v;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (i*2 + j == k) continue;
      v.push_back(x+i), v.push_back(y+j);
      if (s[x+i][y+j] == '0') s[x+i][y+j] = '1';
      else s[x+i][y+j] = '0';
    }
  }

  ans.push_back(v);
}

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  ans.clear();

  for (int i = 0; i < n-2; ++i) {
    for (int j = 0; j < m-1; ++j) {
      if (s[i][j] == '1' && s[i][j+1] == '1') apply(i, j, 3);
      else if (s[i][j] == '1') apply(i, j, 1);
      else if (s[i][j+1] == '1') apply(i, j, 0);
    }
  }

  for (int j = 0; j < m-2; ++j) {
    if (s[n-1][j] == '1' && s[n-2][j] == '1') apply(n-2, j, 1);
    else if (s[n-2][j] == '1') apply(n-2, j, 2);
    else if (s[n-1][j] == '1') apply(n-2, j, 0);
  }

  int a = s[n-2][m-2] - '0', b = s[n-2][m-1] - '0', c = s[n-1][m-2] - '0', d = s[n-1][m-1] - '0';
  int num = a + b*2 + c*4 + d*8;
  int op[4] = {14, 13, 11, 7};

  for (int mask = 0; mask < 16; ++mask) {
    int t = num;
    for (int k = 0; k < 4; ++k) {
      if (mask >> k & 1) t ^= op[k];
    }

    if (t == 0) {
      for (int k = 0; k < 4; ++k) {
        if (mask >> k & 1) apply(n-2, m-2, k);
      }
      break;
    }
  }

  printf("%d\n", (int) ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < 6; ++j) printf("%d ", ans[i][j] + 1);
    printf("\n");
  }
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}