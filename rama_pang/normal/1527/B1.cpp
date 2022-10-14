#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int t00 = 0;
  int t01 = 0;
  int t10 = 0;
  int mid = 1;
  for (int i = 0; i <= n - 1 - i; i++) {
    if (i == n - 1 - i) {
      mid = s[i] == '1';
    } else {
      if (s[i] == '1' && s[n - 1 - i] == '1') {
        continue;
      }
      if (s[i] == '0' && s[n - 1 - i] == '0') {
        t00++;
      }
      if (s[i] == '0' && s[n - 1 - i] == '1') {
        t01++;
      }
      if (s[i] == '1' && s[n - 1 - i] == '0') {
        t10++;
      }
    }
  }
  map<array<int, 6>, int> memo;
  const auto Brute = [&](const auto &self, int t00, int t01, int t10, int mid, int swp, int cur) {
    if (t00 + t01 + t10 == 0 && mid == 1) return 0;
    if (memo.count({t00, t01, t10, mid, swp, cur})) {
      return memo[{t00, t01, t10, mid, swp, cur}];
    }

    if (cur == 0) {
      int res = 1e9;
      if (swp == 0 && t01 + t10 > 0) {
        res = min(res, self(self, t00, t01, t10, mid, 1, cur ^ 1));
      }
      if (mid == 0) {
        res = min(res, 1 + self(self, t00, t01, t10, 1, 0, cur ^ 1));
      }
      if (t01 > 0) {
        res = min(res, 1 + self(self, t00, t01 - 1, t10, mid, 0, cur ^ 1));
      }
      if (t10 > 0) {
        res = min(res, 1 + self(self, t00, t01, t10 - 1, mid, 0, cur ^ 1));
      }
      if (t00 > 0) {
        res = min(res, 1 + self(self, t00 - 1, t01, t10 + 1, mid, 0, cur ^ 1));
      }
      if (t00 > 0) {
        res = min(res, 1 + self(self, t00 - 1, t01 + 1, t10, mid, 0, cur ^ 1));
      }
      return memo[{t00, t01, t10, mid, swp, cur}] = res;
    } else {
      int res = -1e9;
      if (swp == 0 && t01 + t10 > 0) {
        res = max(res, self(self, t00, t01, t10, mid, 1, cur ^ 1));
      }
      if (mid == 0) {
        res = max(res, -1 + self(self, t00, t01, t10, 1, 0, cur ^ 1));
      }
      if (t01 > 0) {
        res = max(res, -1 + self(self, t00, t01 - 1, t10, mid, 0, cur ^ 1));
      }
      if (t10 > 0) {
        res = max(res, -1 + self(self, t00, t01, t10 - 1, mid, 0, cur ^ 1));
      }
      if (t00 > 0) {
        res = max(res, -1 + self(self, t00 - 1, t01, t10 + 1, mid, 0, cur ^ 1));
      }
      if (t00 > 0) {
        res = max(res, -1 + self(self, t00 - 1, t01 + 1, t10, mid, 0, cur ^ 1));
      }
      return memo[{t00, t01, t10, mid, swp, cur}] = res;
    }
  };

  if (mid == 0 && t00 == 0 && t01 == 0 && t10 == 0) {
    cout << "BOB\n";
    return;
  }
  if (mid == 0 && t00 == 0 && t01 + t10 == 1) {
    cout << "DRAW\n";
    return;
  }
  if (mid == 0) {
    cout << "ALICE\n";
    return;
  }
  if (mid == 1 && t00 + t01 + t10 == 0) {
    cout << "DRAW\n";
    return;
  }

  if (mid == 1 && t01 + t10 == 0) {
    cout << "BOB\n";
    return;
  }

  cout << "ALICE\n";
  return;

  for (int t00 = 0; t00 <= 10; t00++) {
    for (int t01 = 0; t01 <= 10; t01++) {
      for (int t10 = 0; t10 <= 10; t10++) {
        int res = Brute(Brute, t00, t01, t10, 1, 0, 0);
        if (res > 0) cout << '+';
        else if (res == 0) cout << '0';
        cout << res << ' ' << t00 << ' ' << t01 << ' ' << t10 << '\n';
      }
    }
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