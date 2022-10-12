#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    while (ans.size() >= 2 && (a[i] < ans.back()) == (ans.back() < ans[ans.size() - 2])) ans.pop_back();
    ans.push_back(a[i]);
  }

  printf("%d\n", (int) ans.size());
  for (int u: ans) printf("%d ", u);
  printf("\n");
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}