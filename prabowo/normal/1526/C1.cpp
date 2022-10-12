#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int ans = 0;
  long long cur = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= 0) {
      cur += a[i];
      ++ans;
    } else {
      if (cur + a[i] >= 0) {
        ++ans;
        cur += a[i];
        pq.push(a[i]);
      } else {
        if (pq.size() > 0 && pq.top() < a[i]) {
          cur -= pq.top();
          pq.pop();
          cur += a[i];
          pq.push(a[i]);
        }
      }
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