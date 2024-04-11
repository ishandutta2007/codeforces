#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
const int MOD = 1000000007;
const int INV2 = 500000004;

int n;
int ans[N];

void init() {
  vector<int> a = {1, 0, 0, 0, 0};
  for (int i = 1; i < N; ++i) {
    vector<int> na(5, 0);
    na[0] = (2LL * a[1] + a[0]) % MOD;
    na[1] = a[0];
    na[2] = (a[4] + a[1]) % MOD;
    na[3] = a[2];
    na[4] = a[3];

    a = na;
    ans[i] = 4LL * a[2] % MOD;
  }
}

int solve() {
  int n;
  scanf("%d", &n);
  printf("%d\n", ans[n-1]);
  return 0;
}

int main() {
  init();
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}