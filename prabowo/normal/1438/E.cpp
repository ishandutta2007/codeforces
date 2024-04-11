#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  vector<pair<int, int>> ans;
  for (int i = 0; i < n; ++i) {
    int lim = 1 << (32 - __builtin_clz(a[i]));
    for (int j = i + 2, sum = a[i + 1]; j < n && sum < lim; sum += a[j++]) {
      if (sum == (a[i] ^ a[j])) {
        ans.emplace_back(i, j);
      }
    }
  }

  reverse(a, a + n);
  for (int i = 0; i < n; ++i) {
    int lim = 1 << (32 - __builtin_clz(a[i]));
    for (int j = i + 2, sum = a[i + 1]; j < n && sum < lim; sum += a[j++]) {
      if (sum == (a[i] ^ a[j])) {
        ans.emplace_back(n - j - 1, n - i - 1);
      }
    }
  }

  sort(ans.begin(), ans.end());
  printf("%d\n", unique(ans.begin(), ans.end()) - ans.begin());
  return 0;
}