#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int isZero = 0, isOne = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) isZero++;
    if (a[i] == 1) isOne++;
  }
  if (isOne == 0) {
    cout << "YES\n";
    return;
  }
  if (isZero > 0) {
    cout << "NO\n";
    return;
  }
  // isOne > 0 and isZero == 0
  // 1 1 3
  // if there exists 2, then cannot
  // otherwise, 
  sort(begin(a), end(a));
  for (int i = 0; i + 1 < n; i++) {
    if (a[i] + 1 == a[i + 1]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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