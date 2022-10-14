#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    cout << max(k - n, 0) + (n > k && n % 2 != k % 2) << "\n";
  }
  return 0;
}