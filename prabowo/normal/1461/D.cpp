#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
const int INF = 1e9;

int n, m;
int a[N];

set<long long> s;
void dfs(vector<int> a) {
  int maxi = -1e9, mini = 1e9;
  long long sum = 0;
  for (int u : a) {
    maxi = max(maxi, u);
    mini = min(mini, u);
    sum += u;
  }

  s.insert(sum);

  int mid = (maxi + mini) / 2;
  if (mid >= maxi || mid < mini) {
    return;
  }

  vector<int> l, r;
  for (int u : a) {
    if (u <= mid) l.push_back(u);
    else r.push_back(u);
  }

  dfs(move(l));
  dfs(move(r));
}

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  s.clear();
  dfs(vector<int>(a, a + n));

  for (int i = 0; i < m; ++i) {
    long long ss;
    scanf("%lld", &ss);
    if (s.count(ss)) printf("Yes\n");
    else printf("No\n");
  }

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