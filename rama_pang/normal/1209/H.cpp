// https://codeforces.com/contest/1209/problem/H
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, L;
  cin >> n >> L;

  double ans = 0;
  auto cmp = [&](const pair<double, double> &a, const pair<double, double> &b) {
    return a.second / a.first < b.second / b.first; // (time, energy), maximize energy / time
  };
  priority_queue<pair<double, double>, vector<pair<double, double>>, decltype(cmp)> pq(cmp);
  pq.emplace(1e18, 1e18);
  auto Process = [&](double d, double v) {
    ans += d / (v + 2); // walk fast all the way
    if (v > 0) {
      pq.emplace(d / v - d / (v + 2), 
                 d / v + d / (v + 2));
    }
    double need = d / (v + 2);
    while (need > 0) {
      auto p = pq.top();
      pq.pop();
      if (need >= p.second) {
        ans += p.first;
        need -= p.second;
      } else {
        double r = need / p.second;
        ans += p.first * r;
        need = 0;
        pq.emplace((1 - r) * p.first, (1 - r) * p.second);
      }
    }
  };

  int last = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    double s;
    cin >> x >> y >> s;
    Process(x - last, 0);
    Process(y - x, s);
    last = y;
  }
  Process(L - last, 0);

  cout << fixed << setprecision(12) << ans << "\n";
  return 0;
}