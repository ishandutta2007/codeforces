#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a;  
  for (int i = 0, j = 0; i < n; i++) {
    if (s[i] == '*') {
      a.emplace_back(j);
    } else {
      j++;
    }
  }
  if (a.empty()) {
    cout << 0 << '\n';
    return;
  }
  int median = a[a.size() / 2];
  long long ans = 0;
  for (auto i : a) ans += abs(i - median);
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