#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
int b[N];
int pre[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int l = 1, r = n;
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;

    for (int i = 0; i < n; ++i) {
      b[i] = (a[i] < mid ? -1 : 1);
      // cerr << b[i] << " ";
    }
    // cerr << endl;

    pre[0] = b[0];
    for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + b[i];

    int mini = 0;
    int sum = pre[k - 1];

    int maxi = -1e9;   
    for (int i = k - 1; i < n; ++i) {
      maxi = max(maxi, sum - mini);

      mini = min(mini, pre[i - k + 1]);
      sum += b[i + 1];
    }

    if (maxi - 1 >= 0) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}