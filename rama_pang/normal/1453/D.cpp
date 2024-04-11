#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

lint Power(lint n, lint x) {
  lint res = 1;
  for (; x > 0; x /= 2, n = 1ll * n * n % MOD) {
    if (x & 1) {
      res = 1ll * res * n % MOD;
    }
  }
  return res;
}

void Main() {
  lint n;
  cin >> n;
  if (n % 2 == 1) {
    cout << -1 << '\n';
    return;
  }
  n /= 2;
  vector<int> lens;
  while (n > 0) {
    lint len = 1;
    while ((1ll << (len + 1)) - 1 <= n) {
      len += 1;
    }
    n -= (1ll << len) - 1;
    lens.emplace_back(len);
  }
  assert(n == 0);
  vector<int> ans;
  for (auto l : lens) {
    ans.emplace_back(1);
    for (int j = 1; j < l; j++) {
      ans.emplace_back(0);
    }
  }
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
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