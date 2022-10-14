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
  int m = 3;
  int k = 2;
  cin >> n;
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[--a]++;
  }
  lint ans = 0;
  lint oth = 0;
  for (int i = 0; i < n; i++) {
    ans += 1ll * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
    ans += 1ll * cnt[i] * (cnt[i] - 1) / 2 * oth;
    ans += 1ll * cnt[i] * oth * (oth - 1) / 2;
    oth += cnt[i];
    if (i - k >= 0) {
      oth -= cnt[i - k];
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