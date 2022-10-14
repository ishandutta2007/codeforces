#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int Power(int n, int x, int mod) {
  if (x == 0) return 1;
  int res = Power(n, x / 2, mod);
  res = 1ll * res * res % mod;
  if (x & 1) res = 1ll * res * n % mod;
  return res;
}

void Main() {
  const int mod = 1e9 + 7;

  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  map<int, int> freq;
  map<int, int> fre2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    fre2[a[i]]++;
    // freq[-a[i]]++;
  }
  if (p == 1) {
    if (n & 1) {
      cout << 1 << "\n";
    } else {
      cout << 0 << "\n";
    }
    return;
  }
  map<int, int> brk;
  for (auto &fr : fre2) {
    if (fr.second >= p) {
      brk[fr.first + 1] = 1;
      fre2[fr.first + 1] += fr.second / p;
      fr.second %= p;
    }
  }
  for (auto fr : fre2) {
    freq[-fr.first] = fr.second;
  }

  bool tip = false;
  int ans = 0;
  for (auto fr : freq) {
    int k = -fr.first;
    int cnt = fr.second;
    int b = brk[k];
    auto nxt = freq.upper_bound(k);
    if (!tip) {
      if (cnt % 2 == 0) {
        continue;
      }
      if (b) {
        freq[-(k - 1)] += p;
      } else {
        tip = true;
        ans = (ans + Power(p, k, mod)) % mod;
      }
    } else {
      ans = (1ll * ans - (1ll * cnt * Power(p, k, mod) % mod)) % mod;
    }
  }

  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}