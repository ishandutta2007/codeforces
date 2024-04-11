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
  int n;
  cin >> n;
  deque<int> a(n);
  for (auto &i : a) cin >> i;
  vector<int> ans;
  while (!a.empty()) {
    ans.emplace_back(a.front());
    a.pop_front();
    if (!a.empty()) {
      ans.emplace_back(a.back());
      a.pop_back();
    }
  }
  for (auto i : ans) cout << i << ' '; cout << '\n';
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