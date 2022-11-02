#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int INF = 1e9 + 7;

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < n; ++i)
    cin >> p[i];
  vector<int> x(m);
  for (int i = 0; i < m; ++i)
    cin >> x[i];
  sort(x.begin(), x.end());
  int j = 0;
  long long ans = 0;
  for (int i = -1; i < m; ++i) {
    int L = (i == -1 ? -INF : x[i]);
    int R = (i + 1 == m ? 2 * INF : x[i + 1]);
    vector<pair<int, int>> events;
    while (j < n && j * 100 <= R) {
      int ll = max(L, 2 * j * 100 - R);
      int rr = min(2 * j * 100 - L, R);
      if (ll < rr) {
        events.emplace_back(ll, p[j]);
        events.emplace_back(rr, -p[j]);
      }
      ++j;
    }
    sort(events.begin(), events.end());
    long long cur = 0;
    for (auto t : events) {
      cur += t.second;
      ans = max(ans, cur);
    }
  }
  cout << ans << '\n';
  return 0;
}