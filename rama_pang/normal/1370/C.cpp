#include <bits/stdc++.h>
using namespace std;

bool IsPrime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string win =  "Ashishgup";
    string lose = "FastestFinger";
    if (n == 1) {
      cout << lose << "\n";
    } else if (n == 2) {
      cout << win << "\n";
    } else if (n & 1) {
      cout << win << "\n";
    } else {
      int even = 0;
      int odd = 0;
      while (n % 2 == 0) {
        n /= 2;
        even++;
      }
      if ((n > 1 && even > 1) || (n > 1 && even == 1 && !IsPrime(n))) {
        odd = 1;
      }
      if (odd) {
        cout << win << "\n";
      } else {
        cout << lose << "\n";
      }
    }
  }
}