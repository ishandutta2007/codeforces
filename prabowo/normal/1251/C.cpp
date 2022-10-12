#include <bits/stdc++.h>
using namespace std;

string s;

int solve() {
  cin >> s;

  string odds, evens;
  for (char c: s) {
    if ((c - '0') % 2) odds += c;
    else evens += c;
  }

  int i = 0, j = 0;
  while (i < odds.size() && j < evens.size()) {
    if (odds[i] < evens[j]) {
      cout << odds[i++];
    } else {
      cout << evens[j++];
    }
  }

  while (i < odds.size()) cout << odds[i++];
  while (j < evens.size()) cout << evens[j++];
  cout << '\n';
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}