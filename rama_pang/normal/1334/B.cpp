#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<lint> a(n);
    for (auto &i : a) cin >> i;
    long long up = 0;
    lint cnt = 0;
    vector<int> b;
    for (int i = 0; i < n; i++) {
      if (a[i] >= x) up += a[i], cnt++;
      else b.emplace_back(a[i]);
    }
    sort(begin(b), end(b));
    while (!b.empty()) {
      if (up + b.back() >= 1ll * (cnt + 1) * x) {
        up += b.back();
        cnt++;
        b.pop_back();
      } else {
        break;
      }
    }
    cout << cnt << "\n";
  }
}