#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s.resize(unique(begin(s), end(s)) - begin(s));
  int cnt = s.size();
  sort(begin(s), end(s));
  s.resize(unique(begin(s), end(s)) - begin(s));
  if (cnt != s.size()) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
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