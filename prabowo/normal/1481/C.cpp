#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m;
int a[N], b[N], c[N];

vector<int> diff[N], same[N];

int ans[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &c[i]);
  }

  for (int i = 1; i <= n; ++i) diff[i].clear(), same[i].clear();

  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      same[a[i]].push_back(i);
    } else {
      diff[b[i]].push_back(i);
    }
  }

  int trash = -1;
  for (int i = m - 1; i >= 0; --i) {
    if (diff[c[i]].size() > 0) {
      trash = diff[c[i]].back();
      ans[i] = diff[c[i]].back();
      diff[c[i]].pop_back();
    } else if (same[c[i]].size() > 0) {
      trash = same[c[i]].back();
      ans[i] = same[c[i]].back();
    } else if (trash != -1) {
      ans[i] = trash;
    } else {
      return 0 * printf("NO\n");
    }
  }

  for (int i = 1; i <= n; ++i) if (diff[i].size() > 0) return 0 * printf("NO\n");

  printf("YES\n");
  for (int i = 0; i < m; ++i) printf("%d ", ans[i] + 1);
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