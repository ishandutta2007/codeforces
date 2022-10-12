#include <bits/stdc++.h>
using namespace std;
 
const int N = 105;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  vector<int> cnt(N, 0);
  for (int i = 0; i < n; ++i) ++cnt[a[i]];


  for (int mex = 0; cnt[mex] > 0; ++mex) printf("%d ", mex), --cnt[mex];
  for (int i = 0; i < N; ++i) while (cnt[i] > 0) {
    printf("%d ", i), --cnt[i];
  }

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