#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k;
int m[N];
int c[N];
int cnt[N];

bool check(int x) {
  int sum = 0;
  for (int i = k-1; i >= 0; --i) {
    sum += cnt[i];
    if (sum > 1LL*c[i]*x) return false;
  }

  return true;
}

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &m[i]);
    ++cnt[--m[i]];
  }
  for (int i = 0; i < k; ++i) {
    scanf("%d", &c[i]);
  }

  int l = 1, r = n;
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  vector<vector<int>> v(ans);
  int idx = 0;
  for (int i = k-1; i >= 0; --i) {
    while (cnt[i] > 0) {
      while (v[idx].size() == c[i]) (++idx) %= ans;
      v[idx].push_back(i+1);
      --cnt[i];
    }
  }

  printf("%d\n", ans);
  for (int i = 0; i < ans; ++i) {
    printf("%d", (int) v[i].size());
    for (int j = 0; j < v[i].size(); ++j) {
      printf(" %d", v[i][j]);
    }
    printf("\n");
  }
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}