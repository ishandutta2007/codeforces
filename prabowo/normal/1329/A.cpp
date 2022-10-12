#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
int l[N];

int ans[N];

int solve() {
  scanf("%d %d", &n, &m);
  long long sum = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &l[i]);
    if (i + l[i] > n) return 0 * printf("-1\n");
    sum += l[i];
  }

  if (sum < n) return 0 * printf("-1\n");

  int lst = n;
  for (int i = m-1; i >= 0; --i) {
    lst -= l[i];
    if (lst < i) lst = i;
    ans[i] = lst + 1;
  }

  for (int i = 0; i < m; ++i) printf("%d ", ans[i]);
    printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}