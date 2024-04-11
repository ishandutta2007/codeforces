#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<pair<lint, lint>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].second;
  }
  sort(begin(a), end(a), [&](pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first, -a.second) < make_pair(b.first, -b.second);
  });

  lint ans = 0;
  lint mx = 0;
  lint cur = a[0].first;
  priority_queue<pair<lint, lint>> pq;
  
  for (int i = 0; i < n; i++) {
    if (a[i].first != cur) {
      while (!pq.empty() && cur < a[i].first) {
        ans += (cur - pq.top().second) * pq.top().first;
        pq.pop();
        cur++;
      }
      cur = a[i].first;
    }
    pq.emplace(a[i].second, a[i].first);
  }

  while (!pq.empty()) {
    ans += (cur - pq.top().second) * pq.top().first;
    pq.pop();
    cur++;
  }

  cout << ans << "\n";
  return 0;
}