#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    int sum = 0;
    for (auto &i : a) {
      sum += i;
    }
    a[0] = min(m, sum);
    cout << a[0] << "\n";
    // sum -= a[0];
    // for (int i = 1; i < n; i++) {
    //   a[i] = sum % m;
    //   sum -= a[i];
    // }
    // for (int i = 0; i < n; i++) {
    //   cout << a[i] << " \n"[i == n - 1];
    // }
  }

}