#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int nine = n;
    int eight = 0;
    nine -= (n + 3) / 4;
    eight += (n + 3) / 4;
    for (int i = 0; i < nine; i++) {
      cout << '9';
    }
    for (int i = 0; i < eight; i++) {
      cout << '8';
    }
    cout << "\n";
  }
  return 0;
}