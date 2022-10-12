#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);

  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }

  long long maks = -1e18;
  long long cur = 0;
  for (int i = 0; i < n-1; ++i) {
    cur = max(cur + a[i], 1LL * a[i]);
    maks = max(maks, cur);
  }

  cur = 0;
  for (int i = 1; i < n; ++i) {
    cur = max(cur + a[i], 1LL * a[i]);
    maks = max(maks, cur);
  }

  if (sum > maks) printf("YES\n");
  else printf("NO\n");
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}