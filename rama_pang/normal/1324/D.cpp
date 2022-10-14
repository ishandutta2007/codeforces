#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : a) {
    int k;
    cin >> k;
    i -= k;
  }
  long long ans = 0;

  // find pairs a[i] + a[j] > 0
  sort(begin(a), end(a));
  vector<int> proc;
  for (int i = 0; i < n; i++) {
    ans += end(proc) - upper_bound(begin(proc), end(proc), -a[i]);
    proc.emplace_back(a[i]);
  }

  cout << ans << "\n";
  return 0;
}