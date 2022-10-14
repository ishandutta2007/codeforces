#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  while (!a.empty() && a.back() == a.size()) {
    a.pop_back();
    n -= 1;
  }
  double ans = 1;
  for (int i = 0; i < m; i++) {
    int r;
    double p;
    cin >> r >> p;
    if (r < a.size()) {
      continue;
    }
    ans *= 1.0 - p;
  }
  if (a.empty()) {
    cout << 1 << '\n';
    return;
  }
  cout << fixed << setprecision(12);
  cout << 1 - ans << '\n';
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