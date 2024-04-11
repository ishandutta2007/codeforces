#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> l(m);
  for (auto &i : l) cin >> i;


  vector<int> p(m);
  int L = 0, R = n - 1;
  for (int i = m - 1; i >= 0; i--) {
    R -= l[i];
    if (R < i) {
      R = i - 1;
    }
    if (R + l[i] >= n) {
      cout << -1 << "\n";
      return 0;
    }
    p[i] = R + 1;
  }

  if (R >= 0) {
    cout << -1 << "\n";
    return 0;
  }

  for (int i = 0; i < m; i++) {
    cout << p[i] + 1 << " \n"[i == m - 1];
  }
}