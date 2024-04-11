#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      for (int u = 0; u < i; ++u) {
        ans.push_back(u);
      }
      ans.push_back(n);
      for (int u = i; u < n; ++u) {
        ans.push_back(u);
      }
      break;
    }
  }

  if (ans.size() == 0) {
    for (int u = 0; u <= n; ++u) ans.push_back(u);
  }

  for (int u : ans) {
    printf("%d ", u + 1);
  }
  printf("\n");
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