#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <bitset>
#include <random>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  const long double PI = atan2(0, -1);

  int n, k;
  cin >> n >> k;
  vector<long double> d(n);
  vector<long double> alpha(n);
  for (int i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    d[i] = sqrtl(x * x + y * y);
    alpha[i] = atan2((long double) y, (long double) x);
    if (alpha[i] < 0)
      alpha[i] += 2 * PI;
  }
  long double left = 0, right = 200001;
  for (int _ = 0; _ < 50; ++_) {
    long double mid = (left + right) / 2;
    vector<pair<long double, int>> events;
    for (int i = 0; i < n; ++i) {
      if (d[i] >= 2 * mid)
        continue;
      long double delta = acos(d[i] / 2 / mid);
      long double L = alpha[i] - delta, R = alpha[i] + delta;
      if (L < 0) {
        events.emplace_back(2 * PI + L, 1);
        events.emplace_back(2 * PI, -1);
        events.emplace_back(0, 1);
        events.emplace_back(R, -1);
      } else if (R > 2 * PI) {
        events.emplace_back(L, 1);
        events.emplace_back(2 * PI, -1);
        events.emplace_back(0, 1);
        events.emplace_back(R - 2 * PI, -1);
      } else {
        events.emplace_back(L, 1);
        events.emplace_back(R, -1);
      }
    }
    sort(events.begin(), events.end());
    int cur = 0;
    int mx = 0;
    for (auto t : events) {
      cur += t.second;
      mx = max(mx, cur);
    }
    if (mx >= k)
      right = mid;
    else
      left = mid;
  }
  cout << setprecision(30) << right << '\n';
  return 0;
}