#include <bits/stdc++.h>
using namespace std;

int n, m, k;

vector<pair<int, string>> v;
void move(int x, string dir) {
  if (k == 0) return;
  int step = min(x, k);
  v.emplace_back(step, dir);
  k -= step;
}

int solve() {
  scanf("%d %d %d", &n, &m, &k);
  if (4*n*m - 2*n - 2*m < k) return 0 * printf("NO\n");

  v.clear();

  for (int i = 1; i < n; ++i) {
    if (m > 1) {
      move(m-1, "R");
      move(m-1, "L");
    }
    move(1, "D");
  }

  if (m > 1) move(m-1, "R");
  for (int i = 1; i < m; ++i) {
    if (n > 1) {
      move(n-1, "U");
      move(n-1, "D");
    }
    move(1, "L");
  }

  if (n > 1) move(n-1, "U");

  printf("YES\n");
  printf("%d\n", (int) v.size());
  for (pair<int, string> p: v) {
    cout << p.first << " " << p.second << "\n";
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