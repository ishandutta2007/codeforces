#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<int> b(n);
  vector<int> cand;
  for (int i = n - 1; i >= 0; i--) {
    if ((i > 0 && a[i - 1] < a[i]) || (i == 0 && a[i] != 0)) {
      b[i] = (i > 0 ? a[i - 1] : 0);
      for (int j = b[i] + 1; j < a[i]; j++) {
        cand.push_back(j);
      }
    } else {
      if (cand.empty()) {
        b[i] = 1e6;
      } else {
        b[i] = cand.back();
        cand.pop_back();
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << "\n";
}