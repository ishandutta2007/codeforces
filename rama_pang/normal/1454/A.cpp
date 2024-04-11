#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    cout << j + 1 << " ";
  }
  cout << "\n";
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