#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int first = s[0] - '0';
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j + 1 < n && s[i] == s[j + 1]) j += 1;
    i = j;
    cnt += 1;
  }
  if (first == 0) {
    cout << max(0, cnt - 2) << '\n';
  } else {
    cout << max(0, cnt - 1) << '\n';
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