#include "bits/stdc++.h"
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (x).size()

using lint = long long;




int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> b(n);
  for (auto &i : b) {
    cin >> i;
  }

  vector<int> a(n);
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      a[i] = b[i];
    } else {
      a[i] = b[i] + x;
      // b = a - x;
    }
    x = max(x, a[i]);
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }

}