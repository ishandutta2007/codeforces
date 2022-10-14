#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  vector<pair<int, int>> bad;

  map<long long, int> freq;
  long long sum = 0;
  freq[0] = -1;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (freq.count(sum)) {
      bad.emplace_back(freq[sum] + 1, i);
      freq[sum] = i;
    } else {
      freq[sum] = i;
    }
  }

  long long ans = 0;

  int mn = n;
  sort(begin(bad), end(bad));
  for (int i = n - 1; i >= 0; i--) {
    while (!bad.empty() && bad.back().first == i) {
      mn = min(mn, bad.back().second);
      bad.pop_back();
    }
    ans += max(0, mn - i);
  }

  cout << ans << "\n";
  return 0;
}