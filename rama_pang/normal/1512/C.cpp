#include <bits/stdc++.h>
using namespace std;

void Main() {
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  int n = a + b;
  vector<pair<int, int>> pos;
  for (int i = 0; i < n / 2; i++) {
    int unkown = 0;
    unkown += s[i] == '?';
    unkown += s[n - i - 1] == '?';
    if (unkown == 0) {
      if (s[i] != s[n - i - 1]) {
        cout << -1 << '\n';
        return;
      }
    } else if (unkown == 1) {
      if (s[i] == '?') {
        s[i] = s[n - i - 1];
      } else {
        s[n - i - 1] = s[i];
      }
    } else {
      pos.emplace_back(i, n - i - 1);
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') a--;
    if (s[i] == '1') b--;
  }
  if (a < 0 || b < 0) {
    cout << -1 << '\n';
    return;
  }
  if ((n & 1) && s[n / 2] == '?') {
    {
      s[n / 2] = '0';
      a--;
      if (a >= 0 && a % 2 == 0 && b % 2 == 0) {
        for (auto i : pos) {
          if (a >= 2) {
            a -= 2;
            s[i.first] = s[i.second] = '0';
          } else {
            b -= 2;
            s[i.first] = s[i.second] = '1';
          }
        }
        assert(a == 0 && b == 0);
        cout << s << '\n';
        return;
      }
      a++;
    }
    {
      s[n / 2] = '1';
      b--;
      if (b >= 0 && a % 2 == 0 && b % 2 == 0) {
        for (auto i : pos) {
          if (a >= 2) {
            a -= 2;
            s[i.first] = s[i.second] = '0';
          } else {
            b -= 2;
            s[i.first] = s[i.second] = '1';
          }
        }
        assert(a == 0 && b == 0);
        cout << s << '\n';
        return;
      }
      b++;
    }
  } else {
    if (a % 2 == 0 && b % 2 == 0) {
      for (auto i : pos) {
        if (a >= 2) {
          a -= 2;
          s[i.first] = s[i.second] = '0';
        } else {
          b -= 2;
          s[i.first] = s[i.second] = '1';
        }
      }
      assert(a == 0 && b == 0);
      cout << s << '\n';
      return;
    }
  }

  cout << -1 << '\n';
  return;
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