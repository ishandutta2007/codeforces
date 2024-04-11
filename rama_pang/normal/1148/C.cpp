#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }  

  vector<pair<int, int>> ans;
  for (int i = 1; i + 1 < n; i++) {
    while (i != a[i]) {
      int j, j2;
      if (i * 2 >= n) {
        j = 0;
        j2 = n - 1;
      } else {
        j2 = 0;
        j = n - 1;
      }
      ans.emplace_back(i, j);
      swap(a[i], a[j]);
      if (a[j] != j) {
        if (2 * abs(a[j] - j) < n) {
          ans.emplace_back(j, j2);
          swap(a[j], a[j2]);
          j = j2;
        }
        if (a[j] != j) {
          int k = a[j];
          ans.emplace_back(j, k);
          swap(a[j], a[k]);
        }
      }
    }
  }

  if (a[0] != 0) {
    ans.emplace_back(0, n - 1);
    swap(a[0], a[n - 1]);
  }

  assert(is_sorted(begin(a), end(a)));

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i.first + 1 << " " << i.second + 1 << "\n";
  }
}