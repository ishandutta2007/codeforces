#include <bits/stdc++.h>
using namespace std;

const int N = 600005;

int n;
long long a[N], b[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &a[i], &b[i]);
  }

  long long ans = 1e18;
  long long sum = 0; queue<int> q;
  for (int i = 0, j = 0; i < n; ++i) {
    if (q.size() && q.front() == i) {
      q.pop();
      sum -= a[i] - b[i-1];
    }
    if (i == j) ++j;
    while (j < i+n) {
      if (a[j % n] <= b[(j-1) % n]) ++j;
      else {
        sum += a[j % n] - b[(j-1) % n];
        q.push(j++);
      }
    }

    ans = min(ans, sum + a[i]);
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}