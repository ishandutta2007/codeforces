#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int nn = n;
  for (char c = 'z'; c >= 'a'; c--) {
    while (true) {
      int del = -1;
      for (int i = 0; i < n; i++) {
        if (s[i] == c) {
          if (i > 0 && s[i - 1] == c - 1) {
            del = i;
            break;
          }
          if (i + 1 < n && s[i + 1] == c - 1) {
            del = i;
            break;
          }
        }
      }
      if (del == -1) {
        break;
      }
      for (int i = del; i + 1 < n; i++) {
        s[i] = s[i + 1];
      }
      s.pop_back();
      n--;
    }
  }

  cout << nn - (int) s.size() << "\n";
  return 0;

}