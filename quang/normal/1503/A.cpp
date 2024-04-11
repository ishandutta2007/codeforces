#include <bits/stdc++.h>

using namespace std;

bool check(const string &u) {
  int cnt = 0;
  for (auto val : u) {
    if (val == '(') cnt++;
    else {
      if (cnt == 0) return false;
      cnt--;
    }
  }
  return cnt == 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n; cin >> n;
    string s;
    cin >> s;
    int num1 = 0;
    for (auto u : s) {
      num1 += (u == '1');
    }
    int num0 = n - num1;
    if (num1 % 2 || num0 % 2) {
      cout << "NO\n";
      continue;
    }
    string a = "";
    string b = "";
    int cnt1 = 0;
    int cnt0 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (cnt1 * 2 < num1) {
          a += '(';
          b += '(';
        } else {
          a += ')';
          b += ')';
        }
        cnt1++;
      } else {
        if (cnt0) {
          a += '(';
          b += ')';
        } else {
          a += ')';
          b += '(';
        }
        cnt0 ^= 1;
      }
    }

    if (check(a) && check(b)) {
      cout << "YES\n";
      cout << a << '\n';
      cout << b << '\n';
    } else cout << "NO\n";
  }
  return 0;
}