#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int cnt = 2 * k - n;
    for (int i = 1; i < cnt; i++) {
      cout << i << ' ';
    }
    for (int i = cnt; i <= k; i++) {
      cout << k - (i - cnt) << ' ';
    }
    cout << '\n';
  }
  return 0;
}