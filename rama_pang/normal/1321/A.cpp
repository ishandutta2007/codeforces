#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> r(n);
  for (auto &i : r) {
    cin >> i;
  }
  vector<int> b(n);
  for (auto &i : b) {
    cin >> i;
  }  
  if (r == b) {
    cout << -1 << "\n";
    return 0;
  }
  int same = 0;
  int sumb = 0;
  int sumr = 0;
  for (int i = 0; i < n; i++) {
    if (r[i] == 1 && b[i] == 1) {
      same++;
    }
    if (b[i] == 1) {
      sumb++;
    }
    if (r[i] == 1) {
      sumr++;
    }
  }
  
  sumb -= same;
  sumr -= same;

  if (sumr == 0) {
    cout << -1 << "\n";
    return 0;
  }

  cout << ceil(1.00 * (sumb + 1) / sumr) << "\n";
  return 0;
}