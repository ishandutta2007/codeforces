#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
 
int n, m, x;
int h[N];
pair<int, int> idx[N];
int ans[N];
 
int solve() {
  scanf("%d %d %d", &n, &m, &x);
 
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h[i]);
    idx[i] = {h[i], i};
  }
 
  sort(idx, idx + n);
 
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < m; ++i) {
    pq.emplace(0, i);
  }
 
  for (int i = 0; i < n; ++i) {
    int th, tidx;
    tie(th, tidx) = pq.top(); pq.pop();
    th = -th;
 
    ans[idx[i].second] = tidx;
    th += idx[i].first;
 
    pq.emplace(-th, tidx);
  }
 
  printf("YES\n");
  for (int i = 0; i < n; ++i) printf("%d ", ans[i] + 1);
  printf("\n");
  return 0;
}
 
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}