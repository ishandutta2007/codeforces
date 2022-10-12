#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int a[N];

int solve() {
  scanf("%d %d", &n, &m);
  vector<int> cnt(n);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a[i]);
    ++cnt[--a[i]];
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; ++i) {
    pq.push(cnt[i]);
  }

  multiset<int> ms(cnt.begin(), cnt.end());

  while (true) {
    int small = *ms.begin();
    int big = *ms.rbegin();
    if (small + 2 >= big) break;
    ms.erase(ms.begin()); ms.erase(prev(ms.end()));
    ms.insert(small + 2);
    ms.insert(big - 1);
  }

  int ans = *ms.rbegin();

  printf("%d\n", ans);
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