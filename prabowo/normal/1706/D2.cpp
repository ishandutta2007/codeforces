#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k;
int a[N];

vector<int> cnt[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  if (n == 1) return 0 * printf("0\n");

  int idx = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && a[j] == a[i]) ++j;

    if (j - i == 1) a[idx++] = a[i];
    else a[idx++] = a[idx++] = a[i];

    i = j;
  }
  n = idx;

  for (int i = 0; i < N; ++i) {
    vector<int>().swap(cnt[i]);
  }

  int maxPtr = 0;
  for (int i = 0; i < n; ++i) {
    cnt[a[i] / k].push_back(i);
    maxPtr = max(maxPtr, a[i] / k);
  }

  int ans = 1e9;
  idx = 0;
  while (true) {
    while (cnt[idx].size() == 0) ++idx;

    ans = min(ans, maxPtr - idx);

    bool done = false;
    for (int i : cnt[idx]) {
      int nd = a[i] / (idx + 1);
      if (nd == 0) {
        done = true;
        break;
      }
      cnt[a[i] / nd].push_back(i);
      maxPtr = max(maxPtr, a[i] / nd);
    }
    vector<int>().swap(cnt[idx]);

    if (done) break;
  }

  printf("%d\n", ans);
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