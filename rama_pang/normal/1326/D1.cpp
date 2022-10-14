#include "bits/stdc++.h"
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (x).size()

using lint = long long;

const lint MOD = 998244353;
const lint KEY = 31;

lint power(lint n, lint x) {
  if (x == 0) {
    return 1;
  }
  if (x & 1) {
    return n * power(n, x - 1) % MOD;
  }
  lint res = power(n, x / 2);
  return res * res % MOD;
}

const lint INV = power(KEY, MOD - 2);

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<lint> hsh(s.size());
  vector<lint> rev(s.size());
  vector<lint> inv(s.size());
  vector<lint> pw(s.size());
  
  for (int i = 0; i < n; i++) {
    inv[i] = power(INV, i);
    pw[i] = power(KEY, i);
  }

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      hsh[i] = hsh[i - 1];
    }
    hsh[i] += (s[i] - 'a' + 1) * power(KEY, i);
    hsh[i] %= MOD;
  }

  reverse(begin(s), end(s));
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      rev[i] = rev[i - 1];
    }
    rev[i] += (s[i] - 'a' + 1) * power(KEY, i);
    rev[i] %= MOD;
  }
  reverse(begin(s), end(s));

  auto getpref = [&](int l, int r) {
    if (l > r) return 0ll;
    lint res = hsh[r];
    if (l > 0) {
      res -= hsh[l - 1];
    }
    res %= MOD;
    if (res < 0) res += MOD;
    res *= inv[l];
    return res % MOD;
  };

  auto getsuff = [&](int l, int r) {
    if (l > r) return 0ll;
    lint res = rev[r];
    if (l > 0) {
      res -= rev[l - 1];
    }
    res %= MOD;
    if (res < 0) res += MOD;
    res *= inv[l];
    return res % MOD;
  };


  pair<int, pair<int, int>> mx = {-1, {-1, -1}};
  for (int i = -1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int len = (i + 1) + (n - j);

      lint fr = getpref(0, i) + pw[i + 1] * getpref(j, n - 1) % MOD;
      lint bk = getsuff(0, n - j - 1) + pw[n - j] * getsuff(n - i - 1, n - 1) % MOD;

      // cout << fr << " " << bk << " " << i << " " << j << "\n";

      fr %= MOD;
      if (fr < 0) fr += MOD;
      bk %= MOD;
      if (bk < 0) bk += MOD;
      if (fr == bk) mx = max(mx, {len, {i, j}});
    }
  }
  // cout << getpref(0, n - 1) << " " << getsuff(0, n - 1) << "\n";
  // cout << mx.first << " " << mx.second.first << " " << mx.second.second << "\n";
  string t;
  for (int i = 0; i <= mx.second.first; i++) {
    t.push_back(s[i]);
  }
  for (int i = mx.second.second; i < n; i++) {
    t.push_back(s[i]);
  }
  cout << t << "\n";

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }


}