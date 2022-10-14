#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int s1 = 1 << n;
    int s2 = 0;
    for (int i = 1; i + 1 <= n / 2; i++) {
      s1 += 1 << i;
    }
    for (int i = 1; i <= n; i++) {
      s2 += 1 << i;
    }
    s2 -= s1;
    cout << abs(s1 - s2) << "\n";
  }

}