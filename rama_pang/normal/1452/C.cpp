#include <bits/stdc++.h>
using namespace std;

void Main() {
  string s;
  cin >> s;
  int a = 0;
  int b = 0;
  int ans = 0;
  for (auto i : s) {
    if (i == '[') {
      a += 1;
    } else if (i == ']') {
      ans += a > 0;
      a -= 1;
    } else if (i == '(') {
      b += 1;
    } else if (i == ')') {
      ans += b > 0;
      b -= 1;
    }
    a = max(a, 0);
    b = max(b, 0);
  }
  cout << ans << "\n";
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