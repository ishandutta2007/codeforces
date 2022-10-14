#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> vv(n);
  iota(begin(vv), end(vv), 0);
  vector<int> ans(n, -1);
  for (int i = 1; i + 1 < n; i += 2) {
    if (k > 0) {
      ans[i] = vv.back();
      vv.pop_back();
      k--;
    }
  }
  if (k != 0) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == -1) {
      ans[i] = vv.back();
      vv.pop_back();
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " \n"[i + 1 == n];
  }
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