#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int MOD = 998244353;

int n;
int a[N];

vector<pair<int, int>> inv[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] > a[i]) {
        inv[i].emplace_back(a[j], j);
      }
    }
  }

  vector<pair<int, int>> ans;
  for (int i = n-1; i >= 0; --i) {
    sort(inv[i].begin(), inv[i].end());
    for (pair<int, int> p: inv[i]) {
      ans.emplace_back(p.second, i);
    }
  }

  printf("%d\n", (int) ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  }
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}