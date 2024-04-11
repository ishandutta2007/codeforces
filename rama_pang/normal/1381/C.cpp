#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> b(n);
  vector<vector<int>> occ(n + 2);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    occ[b[i]].emplace_back(i);
  }
  set<int> allcolors(begin(b), end(b));
  int diff = 1;
  while (allcolors.count(diff)) diff++;
  vector<int> a(n, -1);

  int derange = y - x;
  vector<int> pick;
  deque<int> candidates;
  for (int i = 1; i <= n + 1; i++) {
    if (!occ[i].empty()) {
      candidates.emplace_back(i);
    }
  }
  for (int i = 0; i < derange; i++) {
    int j = candidates.front();
    candidates.pop_front();
    pick.emplace_back(occ[j].back());
    occ[j].pop_back();
    if (!occ[j].empty()) {
      candidates.emplace_back(j);
    }
  }

  if (derange > 0) {
    vector<int> cnt(n + 2);
    int mx = 0;
    for (auto i : pick) {
      cnt[b[i]]++;
      mx = max(mx, cnt[b[i]]);
    }
    sort(begin(pick), end(pick), [&](int i, int j) {
      if (cnt[b[i]] == cnt[b[j]]) {
        return b[i] > b[j];
      }
      return cnt[b[i]] > cnt[b[j]];
    });

    for (int i = int(pick.size()) - 1; i >= mx; i--) {
      a[pick[i - mx]] = b[pick[i]];
    }
    int mxcol = b[pick[0]];
    for (int i = 0; i < mx; i++) {
      if (a[pick[i]] == -1) {
        a[pick[i]] = diff;
      }
    }
    for (int i = mx; i < (int) pick.size(); i++) {
      if (mx > 0 && a[pick[i]] == -1) {
        a[pick[i]] = mxcol;
        mx--;
      }
    }
    for (int i = 0; i < n; i++) {
      if (mx > 0 && a[i] == -1 && b[i] != mxcol) {
        a[i] = mxcol;
        mx--;
      }
    }
    if (mx > 0) {
      cout << "NO\n";
      return;
    }
  }

  for (int i = 0; i < n; i++) {
    if (x > 0 && a[i] == -1) {
      a[i] = b[i];
      x--;
    }
  }
  if (x > 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (auto i : a) {
    if (i == -1) {
      i = diff;
    }
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    Main();
  }  
  return 0;
}