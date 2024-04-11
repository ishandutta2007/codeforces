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
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = n - 1;
  for (int f = 0; f < n; f++) {
    int sum = 0;
    for (int i = 0; i <= f; i++) {
      sum += a[i];
    }
    bool can = true;
    int cur = 0;
    int cnt = 1;
    for (int i = f + 1; i < n; i++) {
      cur += a[i];
      if (cur == sum) {
        cnt += 1;
        cur = 0;
      }
      if (cur > sum) {
        can = false;
        break;
      }
    }
    if (cur == 0) {
      ans = min(ans, n - cnt);
    }
  }
  cout << ans << '\n';
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