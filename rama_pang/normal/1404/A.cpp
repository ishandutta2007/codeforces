#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // s[0] = s[k] = s[2k] = ...
    bool bad = false;
    vector<int> elem(k, -1);
    for (int i = 0; i < k; i++) {
      int cnt0 = 0;
      int cnt1 = 0;
      for (int j = i; j < n; j += k) {
        cnt0 += s[j] == '0';
        cnt1 += s[j] == '1';
      }
      if (cnt0 != 0 && cnt1 != 0) {
        bad = true;
        break;
      } else if (cnt0 == 0 && cnt1 == 0) {
        elem[i] = -1;
      } else {
        elem[i] = cnt0 ? 0 : 1;
      }
    }
    if (bad) {
      cout << "NO\n";
      continue;
    }
    int cnt0 = 0;
    int cnt1 = 0;
    for (int i = 0; i < k; i++) {
      cnt0 += elem[i] == 0;
      cnt1 += elem[i] == 1;
    }
    if (cnt0 <= k / 2 && cnt1 <= k / 2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}