#include <bits/stdc++.h>
using namespace std;

using doub = double;
using lint = long long;

#define alL(x) begin(x), end(x)
#define sz(x) (int) x.size()


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    lint n, m;
    cin >> n >> m;
    lint all = n * (n + 1) / 2;
    if (n == m) {
      cout << all << "\n";
      continue;
    }
    // m < n
    lint zero = n - m;
    lint area = m + 1; // <= n
    lint each = zero / area;
    lint add = zero % area;

    lint orig = area - add;
    all -= orig * (each * (each + 1)) / 2;
    all -= add * (each + 1) * (each + 2) / 2;
    cout << all << "\n";




  }
  


}