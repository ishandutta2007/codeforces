#include "bits/stdc++.h"
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (x).size()

using lint = long long;




int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);


  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << -1 << "\n";
      continue;
    }
    string s;
    int sum = 0;
    for (int i = 1; i < n; i++) {
      sum += 8;
      s.push_back('8');
    }
    s.push_back('3');
    sum += 3;
    if (sum % 3 == 0) {
      s[0] = '9';
    }
    cout << s << "\n";

  }


}