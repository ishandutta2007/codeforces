#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  int res = 0;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      int j = x / i;
      if (i <= n && j <= n) {
        res++;
        if (i != j) {
          res++;
        }
      }
    }
  }
  cout << res << endl;
}