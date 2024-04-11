#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, k;

long long countInv(int n, int k) {
  return 1LL * (n - k) * (n - k);
}

int solve() {
  scanf("%d %d", &n, &k);
  long long inv = countInv(n, k);

  vector<int> p(k);
  int l = 1, r = k;
  for (int i = 0; i < k; ++i) {
    if (i < n - (n-k)*2 - 1) {
      p[i] = l++;
    } else {
      p[i] = r--;
    }
  }

  for (int i = 0; i < k; ++i) printf("%d ", p[i]);
  printf("\n");
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