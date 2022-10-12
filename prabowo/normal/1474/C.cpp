#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000005;

int n, m, k;
int a[N];

int cnt[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n*2; ++i) {
    scanf("%d", &a[i]);
  }

  sort(a, a + n*2);

  for (int j = n*2 - 2; j >= 0; --j) {
    for (int i = 0; i < n*2; ++i) ++cnt[a[i]];

    vector<pair<int, int>> ans;
    int x = a[n*2 - 1] + a[j];
    for (int i = n*2 - 1; i >= 0; --i) {
      if (cnt[a[i]] == 0) continue;
      int p = a[i];
      --cnt[p];
      int q = x - a[i];
      if (q < 0 || q >= N || cnt[q] == 0) break;
      --cnt[q];
      x = p;
      ans.emplace_back(p, q);
    }

    if (ans.size() == n) {
      printf("YES\n%d\n", a[n*2 - 1] + a[j]);
      for (pair<int, int> p : ans) {
        printf("%d %d\n", p.first, p.second);
      }
      return 0;
    }

    for (int i = 0; i < n*2; ++i) cnt[a[i]] = 0;
  }

  printf("NO\n");
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