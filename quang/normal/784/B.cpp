#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << 1;
    return 0;
  }
  int res = 0;
  while (n > 0) {
    int x = n % 16;
    if (x == 0) res++;
    if (x == 4) res++;
    if (x == 6) res++;
    if (x == 8) res += 2;
    if (x == 9) res++;
    if (x == 10) res++;
    if (x == 11) res += 2;
    if (x == 13) res++;
    n /= 16;
  }
  cout << res << endl;
  return 0;
}