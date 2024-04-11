#include <bits/stdc++.h>
using namespace std;

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
    string t;
    for (auto i : s) {
      int later = 0;
      if (t.back() == '1' && i == '0') {
        later = 1;
      }
      while (!t.empty() && (t.back() == '1' && i == '0')) {
        t.pop_back();
      }
      if (!t.empty() && (t.back() == '2' && i == '0')) {
        continue;
      }
      if (later) {
        t.push_back('2');
      } else {
        t.push_back(i);
      }
    }
    for (auto &i : t) {
      if (i == '2') {
        i = '0';
      }
    }
    cout << t << "\n";
  }
  return 0;
}