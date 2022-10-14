#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    int k = n;
    reverse(begin(t), end(t));

    for (int tr = n - 1; tr >= 1; tr--) {
      string nw;
      for (int i = tr - 1; i < n; i++) {
        nw.push_back(s[i]);
      }
      if ((n - tr) % 2 == 0) {
        for (int i = tr - 2; i >= 0; i--) {
          nw.push_back(s[i]);
        }
      } else {
        for (int i = 0; i < tr - 1; i++) {
          nw.push_back(s[i]);
        }
      }
      if (nw <= t) {
        t = nw;
        k = tr;
      }
    }

    cout << t << "\n";
    cout << k << "\n";
  }

}