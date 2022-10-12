#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 1000000007;

int n;
int a[N];
vector<int> edges[N];

// sum, leaf, ans
tuple<long long, int, long long> dfs(int u) {
  long long sum = a[u], ans = 0LL;
  int leaf = (edges[u].size() == 0);
  for (int v: edges[u]) {
    long long nsum, nans;
    int nleaf;
    tie(nsum, nleaf, nans) = dfs(v);
    sum += nsum;
    leaf += nleaf;
    ans = max(ans, nans);
  }

  ans = max(ans, sum / leaf + (sum % leaf > 0));
  return make_tuple(sum, leaf, ans);
}

int solve() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p);
    --p;

    edges[p].push_back(i);
  }
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  printf("%lld\n", get<2>(dfs(0)));
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