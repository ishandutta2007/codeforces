#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int last = 0;

  lint ans = 0;
  lint cur = 0;
  vector<array<lint, 3>> st = {{lint(1e9), 0ll, 0ll}};
  int id = 0;
  for (auto i : s) {
    id++;
    if (i == '0') {
      if (last != 0) {
        for (int j = last; j >= 1; j--) {
          cur += 1ll * (id - j - st.back()[1]) * j;
          st.push_back({j, id - j, 1ll * (id - j - st.back()[1]) * j});
        }
        last = 0;
      }
      ans += cur;
      continue;
    }
    last++;
    while (!st.empty() && st.back()[0] <= last) {
      cur -= st.back()[2];
      st.pop_back();
    }
    ans += 1ll * last * (id - st.back()[1]);
    ans -= 1ll * last * (last - 1) / 2;
    ans += cur;
  }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}