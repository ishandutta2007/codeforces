#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  vector<bool> vis(n + 1);

  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    for (int num = i; num <= n; num <<= 1) {
      ans.push_back(num);
      vis[num] = true;
    }
  }

  printf("2\n");
  for (int p : ans) {
    printf("%d ", p);
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}