#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
pair<int, int> segs[N];

int ans[N];

vector<pair<int, int>> points;

int solve() {
  points.clear();

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    ans[i] = 0;
    scanf("%d %d", &segs[i].first, &segs[i].second);

    points.push_back({segs[i].first, -i-1});
    points.push_back({segs[i].second, i+1});
  }

  sort(points.begin(), points.end());

  set<int> s;

  int cnt = 0;

  bool hasEnd = false;
  for (pair<int, int> p: points) {
    int idx = abs(p.second) - 1;

    if (p.second > 0) {
      s.erase(idx);
      hasEnd = true;

      if (s.size() == 0) {
        ++cnt;
        hasEnd = false;
      }
    } else {
      if (s.size() == 1 && hasEnd) {
        ++ans[*s.begin()];
      }
      s.insert(idx);
    }
  }

  if (cnt == n) return 0 * printf("%d\n", n-1);

  int maks = 0;
  for (int i = 0; i < n; ++i) maks = max(maks, ans[i]);
  printf("%d\n", maks + cnt);

  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}