#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin>> n;
  string s;
  cin >> s;
  int open = 0, close = 0;
  for (auto& i : s) {
    if (i == '(') {
      open++;
    } else {
      close++;
    }
  }
  if (open != close) {
    cout << -1 << "\n";
    return 0;
  }

  vector<int> sum(n);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      sum[i] = sum[i - 1];
    }
    if (s[i] == '(') {
      sum[i]++;
    } else {
      sum[i]--;
    }
  }

  int ans = 0;
  int last = -1;
  for (int i = 0; i < n; i++) {
    if (sum[i] == 0) {
      if (sum[last + 1] > 0) {
        last = i;
        continue;
      }
      ans += i - last;
      last = i;
    }
  }
  // for (int i = 0; i < n; i++) {
  //   cout << sum[i] << " \n"[i == n - 1];
  // }
  cout << ans << "\n";
}