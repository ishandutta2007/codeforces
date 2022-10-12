#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;

int cnt[N];

vector<int> v[N];
bool check(int x) {
  priority_queue<int> pq;
  for (int i = 0; i < n; ++i) {
    v[i].clear();
    if (cnt[i] > 0) {
      pq.push(cnt[i]);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int c: v[i]) pq.push(c);
    if (pq.size() == 0) return false;

    int c = pq.top();
    pq.pop();

    --c;
    if (c > 0) v[i + x + 1].push_back(c);
  }
  return true;
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) cnt[i] = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    --a;

    ++cnt[a];
  }

  int l = 0, r = n-1, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
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
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}