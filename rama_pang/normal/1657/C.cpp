#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  string s;
  cin >> n >> s;
  int op = 0, len = 0;
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == ')' && s[i + 1] == '(') {
      int ok = 0;
      for (int j = i + 2; j < n; j++) {
        if (s[j] == ')') {
          ok = 1;
          op += 1;
          len += j - i + 1;
          i = j;
          break;
        }
      }
      if (!ok) break;
    } else {
      op += 1;
      len += 2;
      i += 1;
    }
  }
  cout << op << ' ' << n - len << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}