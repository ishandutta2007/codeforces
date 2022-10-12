#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int ans[N];

int solve() {
  scanf("%d", &n);
  priority_queue<tuple<int, int, int>> pq;
  pq.push(make_tuple(n, 0, -n+1));

  int idx = 0;
  while (pq.size()) {
    int len, l, r;
    tie(len, l, r) = pq.top();
    l = -l, r = -r;
    pq.pop();

    int mid = (l + r) / 2;
    ans[mid] = ++idx;

    if (l <= mid-1) pq.push(make_tuple(mid - l, -l, -mid+1));
    if (mid+1 <= r) pq.push(make_tuple(r - mid, -mid-1, -r));
  }
  
  for (int i = 0; i < n; ++i) printf("%d%c", ans[i], " \n"[i == n-1]);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}