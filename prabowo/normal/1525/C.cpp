#include <bits/stdc++.h>
using namespace std;
 
const int N = 300005;

int n, m;
pair<int, char> a[N];

int ans[N];
int tans[N];

int solve() {
  map<int, int> order;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    order[a[i].first] = i;
  }
  for (int i = 0; i < n; ++i) {
    getchar();
    scanf("%c", &a[i].second);
  }
  sort(a, a + n);

  for (int i = 0; i < n; ++i) ans[i] = -1;

  auto solve = [&](vector<int> idxs) {
    vector<int> v;
    for (int i : idxs) {
      if (a[i].second == 'L' && v.size() > 0 && a[v.back()].second == 'R') {
        ans[v.back()] = ans[i] = (a[i].first - a[v.back()].first) / 2;
        v.pop_back();
      } else {
        v.push_back(i);
      }
    }
    while (v.size() >= 2 && a[v.back()].second == a[v[v.size() - 2]].second && a[v.back()].second == 'R') {
      int two = v[v.size() - 2];
      ans[v.back()] = ans[two] = (a[v.back()].first - a[two].first) / 2 + (m - a[v.back()].first);
      v.pop_back(); v.pop_back();
    }
    reverse(v.begin(), v.end());
    while (v.size() >= 2 && a[v.back()].second == a[v[v.size() - 2]].second && a[v.back()].second == 'L') {
      int two = v[v.size() - 2];
      ans[v.back()] = ans[two] = (a[two].first - a[v.back()].first) / 2 + (a[v.back()].first);
      v.pop_back(); v.pop_back();
    }
    reverse(v.begin(), v.end());
    if (v.size() == 2) {
      ans[v[0]] = ans[v[1]] = (a[v[0]].first + (m - a[v[1]].first) + m) / 2;
    }
  };

  vector<int> odd, even;
  for (int i = 0; i < n; ++i) {
    if (a[i].first & 1) odd.push_back(i);
    else even.push_back(i);
  }

  solve(odd); solve(even);

  for (int i = 0; i < n; ++i) tans[order[a[i].first]] = ans[i];
  for (int i = 0; i < n; ++i) {
    printf("%d ", tans[i]);
  }
  printf("\n");

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}