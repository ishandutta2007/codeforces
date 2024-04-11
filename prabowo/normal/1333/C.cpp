#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  
  multiset<long long> sums;
  sums.insert(0LL);
  long long cur = 0;
  long long prv = 0;
  int idx = 0;

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    cur += a[i];

    while (sums.count(cur) > 0) {
      sums.erase(sums.find(prv));
      prv += a[idx++];
    }

    ans += sums.size();
    sums.insert(cur);
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