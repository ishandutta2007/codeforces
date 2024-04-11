#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

template<typename T>
void Add(T &a, lint b) {
  a += b;
  a -= (a >= MOD) * MOD;
}

lint Power(lint x, lint y) {
  lint res = 1;
  for (; y; y /= 2, x = 1ll * x * x % MOD) {
    if (y & 1) {
      res = 1ll * res * x % MOD;
    }
  }
  return res;
} 

void Main() {
  int x;
  cin >> x;
  if (x > 45) {
    cout << -1 << '\n';
  } else {
    vector<int> ans;
    int p = 9;
    while (x > 0) {
      ans.emplace_back(min(x, p));
      x -= min(x, p);
      p--;
    }
    sort(begin(ans), end(ans));
    for (auto i : ans) cout << i; cout << '\n';
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