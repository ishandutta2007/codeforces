#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  cin >> n >> k;
  long long res = 0;
  for (int i = 1; i <= k; i++) {
    int len = n - i * 2;
    if (len < 0) {
      break;
    }
    res += len * 2 + 1;
  }
  cout << res << endl;
  return 0;
}