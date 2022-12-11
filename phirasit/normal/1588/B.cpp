#include <bits/stdc++.h>

using namespace std;

long long ask(int l, int r) {
  cout << "? " << l << " " << r << endl;
  long long ans;
  cin >> ans;
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    const long long max_val = ask(1, n);
    int a = 1, b = n;
    while (a < b) {
      int mid = (a + b) / 2 + 1;
      if (ask(1, mid) < max_val) {
        a = mid;
      } else {
        b = mid - 1;
      }
    }

    const long long k = a + 1;
    long long jk_len = max_val - ask(1, k-1);
    const long long j = k - jk_len;
    long long ij_len = ask(1, j-1) - ask(1, j-2);
    const long long i = j - 1 - ij_len;

    cout << "! " << i << " " << j << " " << k << endl;
  }

  return 0;
}