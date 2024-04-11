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
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    int even = 0;
    int odd = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] & 1) {
        odd++;
      } else {
        even++;
      }
    }
    if (even % 2 == 0 && odd % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    // even, odd % 2 == 1
    int can = 0;
    vector<int> freq(105);
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        freq[a[i]]++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 1) {
        if (max(freq[a[i] - 1], freq[a[i] + 1]) > 0) {
          can = 1;
          break;
        } 
      }
    }
    if (can) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}