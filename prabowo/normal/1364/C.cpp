#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }

  vector<int> ans;
  vector<int> use;

  for (int i = n-1; i >= 0; --i) {
    if (a[i] < a[i+1]) {
      ans.push_back(a[i]);
      for (int j = a[i] + 1; j < a[i+1]; ++j) {
        use.push_back(j);
      }
    } else {
      if (use.size()) {
        ans.push_back(use.back());
        use.pop_back();
      } else {
        ans.push_back(n);
      }
    }
  }

  // if (use.size() > 0) return 0 * printf("-1\n");

  reverse(ans.begin(), ans.end());
  for (int u: ans) printf("%d ", u); printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}