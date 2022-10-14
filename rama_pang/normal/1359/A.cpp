#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int each = n / k;
    int win = min(each, m);
    m -= win;
    m = ceil(1.00 * m / (k - 1));
    // cout << m << " ";
    cout << win - m << "\n";
  }
}