// https://codeforces.com/contest/802/problem/N
// https://codeforces.com/contest/802/problem/O
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  auto Solve = [&](long long lambda) -> pair<long long, int> {
    priority_queue<pair<long long, int>> pq;
    long long sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      pq.emplace(-a[i], 0);
      pq.emplace(b[i] - lambda, 1);
      pq.pop();
    }
    while (!pq.empty()) {
      sum += pq.top().first;
      cnt += pq.top().second;
      pq.pop();
    }
    return {sum, cnt};
  };

  long long lo = 0, hi = 1e10;
  while (lo < hi) {
    long long md = (lo + hi + 1) / 2;
    if (Solve(md).second <= k) {
      lo = md;
    } else {
      hi = md - 1;
    }
  }

  cout << (Solve(lo).first + lo * k) << "\n";
  return 0;
}