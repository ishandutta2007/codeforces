#include <bits/stdc++.h>
using namespace std;
 
const int N = 505;

int n;
char s[N][N];

int solve() {
  scanf("%d", &n);
  vector<pair<int, int>> stars;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '*') {
        stars.emplace_back(i, j);
      }
    }
  }

  if (stars[0].first == stars[1].first) {
    int x = (stars[0].first + 1) % n;
    s[x][stars[0].second] = s[x][stars[1].second] = '*';
  } else if (stars[0].second == stars[1].second) {
    int y = (stars[0].second + 1) % n;
    s[stars[0].first][y] = s[stars[1].first][y] = '*';
  } else {
    s[stars[0].first][stars[1].second] = s[stars[1].first][stars[0].second] = '*';
  }

  for (int i = 0; i < n; ++i) printf("%s\n", s[i]);

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