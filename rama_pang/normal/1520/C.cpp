#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  if (n == 2) {
    cout << -1 << '\n';
    return;
  }
  if (n == 3) {
    cout << "2 9 7" << '\n';
    cout << "4 6 3" << '\n';
    cout << "1 8 5" << '\n';
    return;
  }
  if (n == 4) {
    cout << "5 15 11 4\n";
    cout << "12 6 3 14\n";
    cout << "16 2 7 10\n";
    cout << "1 9 13 8\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    int val = i * n + 1;
    vector<int> a(n);
    for (int j = 0; j < n; j += 2) {
      a[j] = val++;
    }
    for (int j = 1; j < n; j += 2) {
      a[j] = val++;
    }
    for (int j = 0; j < n; j++) {
      cout << a[j] << ' ';
    }
    cout << '\n';
  }
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