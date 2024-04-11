#include <bits/stdc++.h>
using namespace std;

long long n;

vector<int> a[3];

int solve() {
  scanf("%lld", &n);
  --n;

  long long nn = n / 3;

  int len = 0;
  long long cur = 1;
  while (cur <= nn) {
    nn -= cur;
    ++len;
    cur *= 4;
  }

  vector<int> v(len, 0);
  for (int i = len-1; i >= 0; --i) {
    v[i] = nn % 4;
    nn /= 4;
  }

  a[0] = {0, 1, 2, 3};
  a[1] = {0, 2, 3, 1};
  a[2] = {0, 3, 1, 2};

  long long ans = (n % 3 + 1);

  for (int i: v) {
    ans *= 4;
    ans += a[n % 3][i];
  }

  // if (n % 3 == 0) cout << endl;
  // cout << bitset<8>(ans) << endl;

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}