#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  int ptr = 0;
  multiset<int> pending;
  int last = -1;
  for (auto i : b) {
    while (true) {
      if (a[ptr] == i) {
        last = i;
        ptr += 1;
        break;
      }
      if (last == i && pending.find(last) != end(pending)) {
        pending.erase(pending.find(last));
        break;
      } else if (ptr < n) {
        pending.emplace(a[ptr]);
        ptr += 1;
      } else {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}