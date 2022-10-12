#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;

int n, k;
int a[N];

vector<int> pos;

int solve() {
  scanf("%d %d", &n, &k);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);

    if (a[i] > n-k) {
      pos.push_back(i);
      ans += a[i];
    }
  }

  long long ans2 = 1;
  for (int i = 1; i < pos.size(); ++i) {
    ans2 = 1LL * ans2 * (pos[i] - pos[i-1]) % MOD;
  }

  printf("%lld %lld\n", ans, ans2);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}