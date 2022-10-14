#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(10);
  for (int i = 1; i < 10; i++) {
    cin >> a[i];
  }
  a[0] = 1e9;
  string ans;
  int mn = min_element(begin(a), end(a)) - begin(a);
  int max_digits = n / a[mn];
  for (int i = 0; i < max_digits; i++) {
    ans.push_back(mn + '0');
  }
  n %= a[mn];
  int ptr = 0;
  for (int i = 9; i > mn; i--) {
    a[i] -=  a[mn];
    while (ptr < (int) ans.size() && n >= a[i]) {
      ans[ptr] = i + '0';
      ptr++;
      n -= a[i];
    }
  }
  if (ans.empty()) ans = "-1";
  cout << ans << "\n";
  return 0;
}