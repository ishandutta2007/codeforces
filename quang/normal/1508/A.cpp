#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string a[3];
    cin >> a[0] >> a[1] >> a[2];
    vector<int> zero, one;
    for (int i = 0; i < 3; i++) {
      int num0 = 0;
      for (auto u : a[i]) {
        num0 += u == '0';
      }
      if (num0 >= n) {
        zero.push_back(i);
      } else {
        one.push_back(i);
      }
    }

    auto get = [&](const vector<int> &s, char c) {
      vector<string> chunks(n + 1, "");
      for (int i = 0; i < 2; i++) {
        int id = s[i];
        int cur = 0;
        for (auto u : a[id]) {
          if (cur < n && u == c) cur++;
          else {
            chunks[cur] += u;
          }
        }
      }
      string res = "";
      for (int i = 0; i < n; i++) {
        res += chunks[i];
        res += c;
      }
      res += chunks.back();
      return res;
    };
    if (zero.size() >= 2) {
      cout << get(zero, '0') << '\n';  
    } else {
      cout << get(one, '1') << '\n';
    }
  }
  return 0;
}