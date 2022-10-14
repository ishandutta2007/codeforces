#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cout << i << " \n"[i == n];
    }
  }
  return 0;
}