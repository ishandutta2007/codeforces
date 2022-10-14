#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] += 1;
  }
  for (auto [c, v] : mp) {
    if (v & 1) {
      cout << "-1\n";
      return;
    }
  }
  vector<int> reps;
  vector<pair<int, int>> ops;
  const auto Operation = [&](int pos, int val) {
    ops.emplace_back(pos, val);
    a.insert(begin(a) + pos, val);
    a.insert(begin(a) + pos, val);
  };
  while (!a.empty()) {
    int piv = -1;
    vector<int> vi;
    for (int i = int(a.size()) - 2; i >= 0; i--) {
      if (a[i] == a.back()) {
        piv = i;
        break;
      } else {
        vi.emplace_back(a[i]);
      }
    }
    // cout << piv << endl;

    assert(piv != -1);
    int cnt = 0;
    for (auto v : vi) {
      Operation(piv + cnt, v);
      cnt += 1;
    }
    reps.emplace_back((vi.size() + 1) * 2);
    // for (auto i : a) cout << i << ' '; cout << '\n';
    for (int i = 0; i < int(vi.size() + 1) * 2; i++) a.pop_back();
    // return;
  }
  reverse(begin(reps), end(reps));
  cout << ops.size() << '\n';
  for (auto [x, y] : ops) cout << x << ' ' << y << '\n';
  cout << reps.size() << '\n';
  for (auto r : reps) cout << r << ' '; cout << '\n';
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