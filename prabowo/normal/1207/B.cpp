#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, m;
int a[N][N];
bool used[N][N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  vector<pair<int, int>> ans;

  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m-1; ++j) {
      if (a[i][j] == 1 && a[i+1][j] == 1 && a[i][j+1] == 1 && a[i+1][j+1] == 1) {
        used[i][j] = used[i+1][j] = used[i][j+1] = used[i+1][j+1] = true;
        ans.emplace_back(i, j);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 1 && !used[i][j]) return 0 * printf("-1\n");
    }
  }

  printf("%d\n", (int) ans.size());
  for (pair<int, int> p: ans) {
    printf("%d %d\n", p.first + 1, p.second + 1);
  }
  return 0;
}


int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}