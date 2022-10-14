#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, k;
  cin >> n >> k;
  string a, b;
  cin >> a >> b;
  vector<int> cnta(26);
  vector<int> cntb(26);
  for (auto i : a) {
    cnta[i - 'a'] += 1;
  }
  for (auto i : b) {
    cntb[i - 'a'] += 1;
  }
  for (int i = 0; i < 26; i++) {
    if (cnta[i] < cntb[i]) {
      cout << "NO\n";
      return;
    }
    int diff = cnta[i] - cntb[i];
    if (i == 25 && diff > 0) {
      cout << "NO\n";
      return;
    }
    if (diff % k != 0) {
      cout << "NO\n";
      return;
    }
    if (diff > 0) {
      cnta[i + 1] += diff;
    }
  }

  cout << "YES\n";
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