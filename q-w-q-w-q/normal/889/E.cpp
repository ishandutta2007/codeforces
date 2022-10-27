#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

typedef long long i64;

int n;
priority_queue<pair<i64, i64>> q;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  i64 t;
  cin >> t;
  q.push(make_pair(t - 1, 0));
  for (int i = 1; i != n; i++) {
    cin >> t;
    i64 tp = -1;
    while (!q.empty()) {
      if (q.top().first < t)
        break;
      auto g = q.top();
      q.pop();
      i64 e = g.first / t;
      q.push(make_pair(g.first % t, g.second + e * t * i));
      tp = max(tp, g.second + (e - 1) * t * i);
    }
    if (tp != -1)
      q.push(make_pair(t - 1, tp));
  }

  i64 ans = 0;
  while (!q.empty()) {
    ans = max(ans, q.top().first * n + q.top().second);
    q.pop();
  }
  cout << ans;
}