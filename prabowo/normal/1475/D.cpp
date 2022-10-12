#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m;
int a[N];
int b[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }

  vector<int> ones, twos;
  for (int i = 0; i < n; ++i) {
    if (b[i] == 1) ones.push_back(a[i]);
    else twos.push_back(a[i]);
  }
  sort(ones.begin(), ones.end());
  sort(twos.begin(), twos.end());

  long long sum = 0;
  for (int one : ones) sum += one;

  int cur = 0;
  while (cur < ones.size() && sum - ones[cur] >= m) {
    sum -= ones[cur++];
  }
  int ans = -1;
  if (sum >= m) ans = (int) ones.size() - cur;
  // cerr << ans << " " << sum << endl;

  for (int i = (int) twos.size() - 1; i >= 0; --i) {
    sum += twos[i];
    while (cur < ones.size() && sum - ones[cur] >= m) {
      sum -= ones[cur++];
    }
    if (sum >= m) {
      int res = 2 * ((int) twos.size() - i) + ((int) ones.size() - cur);
      if (ans == -1 || res < ans) ans = res;
    }
  }

  printf("%d\n", ans);
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