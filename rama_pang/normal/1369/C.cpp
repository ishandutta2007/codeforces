#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    vector<int> w(k);
    for (auto &i : w) {
      cin >> i;
    }
    sort(begin(a), end(a));
    sort(begin(w), end(w));
    reverse(begin(w), end(w));
    vector<int> big;
    long long ans = 0;
    for (int i = 0; i < k; i++) {
      ans += a.back();
      big.emplace_back(a.back());
      a.pop_back();
      w[i]--;
    }
    sort(begin(big), end(big));
    reverse(begin(a), end(a));
    for (int i = 0; i < k; i++) {
      if (w[i] == 0) {
        ans += big.back();
        big.pop_back();
        continue;
      }
      ans += a.back();
      for (int j = 0; j < w[i]; j++) {
        a.pop_back();
      }
    }
    cout << ans << "\n";
  }
  return 0;
}