#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<int> ans(n);
    pq.push({n, {-0, -(n - 1)}});
    int it = 1;
    while (!pq.empty()) {
      int l = - pq.top().second.first;
      int r = - pq.top().second.second;
      pq.pop();
      if (l > r) continue;
      int mid = (l + r) / 2;
      ans[(l + r) / 2] = it++;
      pq.push({mid - l, {-l, -(mid - 1)}});
      pq.push({r - mid, {-(mid + 1), -r}});
    }

    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  } 
}