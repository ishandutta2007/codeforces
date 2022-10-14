#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  lint sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  // sum/n = (sum - a[i] - a[j])/(n - 2)
  // sum/n*(n - 2) = sum - a[i] - a[j]
  // a[i] + a[j] = sum - sum/n*(n - 2)
  // n(a[i] + a[j]) = sum * 2

  lint ans = 0;
  map<lint, int> freq;
  for (int i = 0; i < n; i++) {
    ans += freq[-1ll * n * a[i] + sum * 2];
    freq[1ll * n * a[i]] += 1;
  }
  cout << ans << '\n';
  return;
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