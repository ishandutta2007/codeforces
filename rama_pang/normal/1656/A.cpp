#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  pair<int, int> mn = {2e9, -1};
  pair<int, int> mx = {-2e9, -1};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mn = min(mn, {a[i], i});
    mx = max(mx, {a[i], i});
  }
  cout << mn.second + 1 << ' ' << mx.second + 1 << '\n';
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