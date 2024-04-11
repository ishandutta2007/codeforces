#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) {
      cin >> u;
    }
    vector<int> cur;
    for (int u : a) {
      if (u == 1) {
        cur.push_back(u);
      } else {
        while (!cur.empty() && cur.back() + 1 != u) cur.pop_back();
        assert(!cur.empty());
        cur.pop_back();
        cur.push_back(u);
      }

      for (int i = 0; i < cur.size(); i++) {
        cout << cur[i];
        if (i + 1 < cur.size()) cout << '.';
      }
      cout << '\n';
    }
  }
  return 0;
}