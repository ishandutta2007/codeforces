#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MAXA = 4005;

int n, p;
int a[N];

int cnt[MAXA];
int pre[MAXA];

int solve() {
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i]];
  }

  for (int i = 1; i < MAXA; ++i) {
    pre[i] = pre[i-1] + cnt[i];
  }

  vector<int> ans;
  for (int i = 1; i < 2000; ++i) {
    bool ok = true;
    int cur = pre[i];
    for (int j = 0; j < n; ++j) {
      if (cur % p == 0) {
        ok = false;
        break;
      }

      --cur;
      cur += cnt[i + j + 1];
    }

    if (ok) ans.push_back(i);
  }

  printf("%d\n", (int) ans.size());
  for (int u: ans) printf("%d ", u);
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}