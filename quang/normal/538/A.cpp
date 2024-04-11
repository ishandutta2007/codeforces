#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
  cin >> s;
  n = s.size();
  for (int i = 0; i < s.size(); i++) {
    for (int j = i; j < s.size(); j++) {
      string s2 = s;
      s2.erase(i, j - i + 1);
      if (s2 == "CODEFORCES") {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}