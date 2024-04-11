#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k;
int a[N];
int t[N];

int pre[N];
int preAwake[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t[i]);
  }

  for (int i = 0; i < n; ++i) {
    pre[i] = pre[i-1] + a[i];
    preAwake[i] = preAwake[i-1] + a[i] * t[i];
  }

  int ans = 0;
  for (int i = 0; i < n-k+1; ++i) {
    int sum = preAwake[i-1] + (preAwake[n-1] - preAwake[i+k-1]);
    sum += pre[i+k-1] - pre[i-1];
    ans = max(ans, sum);
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}