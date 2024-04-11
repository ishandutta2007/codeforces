#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> fs;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        fs.emplace_back(i);
        fs.emplace_back(n / i);
      }
    }
    int ans = n - 1;
    pair<int, int> p = {1, n - 1};
    for (auto f : fs) {
      int mul = n / f;
      if (ans > max(f, (mul - 1) * f)) {
        ans = max(f, (mul - 1) * f);
        p.first = f;
        p.second = (mul - 1) * f;
      }
    }
    cout << p.first << " " << p.second << "\n";
  }
}