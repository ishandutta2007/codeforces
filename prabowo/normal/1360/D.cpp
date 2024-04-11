#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, k;

vector<int> factorize(int n) {
  vector<int> ret;
  for (int i = 1; i*i <= n; ++i) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i*i != n) ret.push_back(n/i);
    }
  }
  return ret;
}

int solve() {
  scanf("%d %d", &n, &k);
  int ans = 1;
  for (int f: factorize(n)) {
    if (f <= k) ans = max(ans, f);
  }
  printf("%d\n", n/ans);
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}