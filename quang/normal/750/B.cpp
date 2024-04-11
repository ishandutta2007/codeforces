#include <bits/stdc++.h>

using namespace std;

int n;
int t;
string dir;

int main() {
  cin >> n;
  int pos = 20000;
  for (int i = 1; i <= n; i++) {
    cin >> t >> dir;
    if (pos == 20000 || pos == 0) {
      if (dir == "West" || dir == "East") {
        cout << "NO";
        return 0;
      }
    }
    if (dir == "South") {
      pos -= t;
    }
    if (dir == "North") {
      pos += t;
    }
    if (pos < 0 || pos > 20000) {
      cout << "NO" << endl;
      return 0;
    }
  }
  puts(pos == 20000 ? "YES" : "NO");
  return 0;
}