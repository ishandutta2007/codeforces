#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    lint n, l, r;
    cin >> n >> l >> r;
    vector<lint> nw;
    for (int i = 1; i < n; i++) {
      nw.emplace_back(2 * (n - i));
    }
    vector<lint> ans;
    vector<lint> gen;

    for (int i = 0; i < nw.size(); i++) {
      if (l <= nw[i]) {
        int pv = i;
        while (gen.size() < r + 2000) {
          pv++;
          if (pv > n) break;
          for (int j = pv + 1; j <= n; j++) {
            gen.emplace_back(pv);
            gen.emplace_back(j);
          }
        }
        break;
      } else {
        l -= nw[i];
        r -= nw[i];
      }
    }
    // for (int i = 0; i < gen.size(); i++) {
    //   cout << gen[i] << " ";
    // }
    // cout << "\n";
    gen.emplace_back(1);
    for (int i = l - 1; i < r; i++) {
      cout << gen[i] << " ";
    }
    cout << "\n";
  }
}