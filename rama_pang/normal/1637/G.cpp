#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << -1 << '\n';
    return;
  }
  int x = 1;
  while (x < n) x *= 2;

  vector<int> precomp(x + 1);
  for (int i = 0; i <= x; i++) {
    int z = 1;
    while (z < i) z *= 2;
    precomp[i] = z;
  }

  int incur = 0;
  int maxx = n;
  vector<int> cur(n + 1);
  multiset<int> other;
  for (int i = 1; i <= n; i++) {
    incur += 1;
    cur[i] += 1;
  }
  vector<array<int, 2>> ans;
  while (incur > 0) {
    while (cur[maxx] == 0) maxx--;
    for (int c = maxx; c >= 1; ) {
      if (cur[c] == 0) {
        c--;
        continue;
      }
      if (c == 0 || __builtin_popcount(c) == 1) {
        other.emplace(c);
        cur[c]--;
        incur--;
        continue;
      }
      int z = precomp[c];
      if (cur[z - c] == 0) {
        c--;
        continue;
      }
      incur--;
      cur[c]--;
      cur[z - c]--;
      other.emplace(z);
      int nw = abs(c - (z - c));
      cur[nw] += 1;
      ans.push_back({c, z - c});
      break;
    }
  }

  map<int, int> cnt;
  for (auto elem : other) {
    if (elem == x) {
      continue;
    }
    cnt[elem] += 1;
  }
  for (auto [c1, c2] : cnt) {
    if (c1 == 0) {
      break;
    }
    if (c2 >= 2) {
      ans.push_back({c1, c1});
      other.erase(other.find(c1));
      other.erase(other.find(c1));
      other.emplace(c1 + c1);
      other.emplace(0);
      break;
    }
  }
  assert(other.find(0) != end(other));
  other.erase(other.find(0));
  while (true) {
    auto it = begin(other);
    if (*it == x) {
      ans.push_back({0, x});
      break;
    }
    int val = *it;
    other.erase(it);
    ans.push_back({0, val});
    ans.push_back({val, val});
    other.emplace(2 * val);
  }

  cout << ans.size() << '\n';
  for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}