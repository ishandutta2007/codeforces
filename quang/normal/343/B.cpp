#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  if (s.size() % 2) {
    puts("NO");
    return 0;
  }
  int sum = 0;
  for (int i = 0; i < s.size(); i++) {
    int type = (s[i] == '+');
    int pos = (i % 2);
    if (type ^ pos) {
      sum++;
    } else {
      sum--;
    }
  }
  cout << (sum ? "NO" : "YES");
  return 0;
}