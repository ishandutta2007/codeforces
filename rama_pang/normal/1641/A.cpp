#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  lint n, x;
  cin >> n >> x;
  vector<lint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  multiset<lint> s;
  for (auto i : a) s.emplace(i);
  sort(begin(a), end(a));
  int ans = 0;
  while (!s.empty()) {
    lint u = *begin(s);
    s.erase(begin(s));
    if (s.count(u * x)) {
      s.erase(s.find(u * x));
    } else {
      ans += 1;
    }
  }
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