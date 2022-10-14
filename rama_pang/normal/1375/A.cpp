#include <bits/stdc++.h>
using namespace std;
using lint = long long;


void Main() {
  int n;
  cin >> n;
  vector<lint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i & 1) {
      a[i] = abs(a[i]);
    } else {
      a[i] = -abs(a[i]);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}