#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint MOD;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n >> MOD;
  vector<lint> a(n);
  map<int, int> freq;
  for (auto &i : a) {
    cin >> i;
    freq[i % MOD]++;
  }

  if (freq.size() != n) {
    cout << 0 << "\n";
    return 0;
  }

  lint ans = 1;
  for (int i = 0; i < n; i++) {
    // cout << a[i] << " \n"[i == n - 1];
    for (int j = i + 1; j < n; j++) {
      ans *= abs(a[i] - a[j]);
      ans %= MOD;
    }
  }

  cout << ans << "\n";

}