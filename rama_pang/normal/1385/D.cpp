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
    string s;
    cin >> s;
    function<int(int, int, char)> Solve = [&](int l, int r, char c) {
      if (l == r) {
        return c == s[l] ? 0 : 1;
      }
      int ll = 0, rr = 0;
      int md = (l + r) / 2;
      for (int i = l; i <= md; i++) {
        ll += s[i] != c;
      }
      for (int i = md + 1; i <= r; i++) {
        rr += s[i] != c;
      }
      return min(Solve(l, md, c + 1) + rr, Solve(md + 1, r, c + 1) + ll);
    };
    cout << Solve(0, n - 1, 'a') << "\n";
  } 
  return 0;
}