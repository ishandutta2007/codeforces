#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

long long suf[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  long long cur = 0;
  for (int i = n-1; i >= 0; --i) {
    cur -= a[i];

    suf[i] = max(cur, a[i] + suf[i+1]);
    // cerr << suf[i] << endl;
  }

  long long ans = suf[0];
  cur = 0;
  for (int i = 0; i < n; ++i) {
    cur -= a[i];
    ans = max(ans, cur + suf[i+1]);
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}