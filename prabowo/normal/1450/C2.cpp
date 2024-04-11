#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int n;
char s[N][N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%s", s[i]);

  int cnt[2][3] = {0, 0, 0, 0, 0, 0};
  int k = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '.') continue;
      ++cnt[s[i][j] == 'O'][(i + j) % 3];
      ++k;
    }
  }

  for (pair<int, int> p : vector<pair<int, int>>({{0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}})) {
    if (cnt[0][p.first] + cnt[1][p.second] <= k / 3) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (s[i][j] == '.') {
            printf(".");
          } else if ((i + j) % 3 == p.first) {
            printf("O");
          } else if ((i + j) % 3 == p.second) {
            printf("X");
          } else {
            printf("%c", s[i][j]);
          }
        }
        printf("\n");
      }
      return 0;
    }
  }

  assert(0);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}