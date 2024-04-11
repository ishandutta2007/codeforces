#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  string ops;
  cin >> ops;
  
  if (ops.size() == 1) {
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ops;
      }
      cout << a[i];
    }
    cout << '\n';
    return;
  }

  if (count(begin(ops), end(ops), '*') == 0) {
    assert(count(begin(ops), end(ops), '+') == 1);
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << '+';
      }
      cout << a[i];
    }
    cout << '\n';
    return;
  }

  if (count(begin(ops), end(ops), '+') == 0) {
    assert(count(begin(ops), end(ops), '*') == 1);
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        if (a[i] == 0) {
          cout << '-';
        } else {
          cout << '*';
        }
      }
      cout << a[i];
    }
    cout << '\n';
    return;
  }

  assert(count(begin(ops), end(ops), '+') == 1);
  assert(count(begin(ops), end(ops), '*') == 1);
  
  string ans(n, '+');
  vector<int> dp(n + 1);
  vector<int> prv(n + 1);
  const auto Solve = [&](int L, int R) {
    while (L <= R && a[L] == 1) {
      ans[++L] = '+';
    }
    while (L <= R && a[R] == 1) {
      ans[R--] = '+';
    }
    if (L > R) {
      return;
    }
    long long mul = 1;
    for (int i = L; i <= R; i++) {
      mul *= a[i];
      if (mul > 1e7) {
        break;
      }
    }
    if (mul > 1e7) {
      for (int i = L + 1; i <= R; i++) {
        ans[i] = '*';
      }
      return;
    }

    for (int i = L; i <= R + 1; i++) {
      dp[i] = prv[i] = -1;
    }
    dp[L] = 0;
    for (int i = L; i <= R; i++) {
      if (a[i] == 1) {
        dp[i + 1] = dp[i] + 1;
        prv[i + 1] = i;
        continue;
      }
      int mul = 1;
      for (int j = i; j >= L; j--) { // only O(log(1e7)) times
        mul *= a[j];
        if (dp[i + 1] < dp[j] + mul) {
          dp[i + 1] = dp[j] + mul;
          prv[i + 1] = j;
        }
      }
    }
    for (int i = R + 1; i > L; i = prv[i]) {
      for (int j = prv[i] + 1; j < i; j++) {
        ans[j] = '*';
      }
      ans[prv[i]] = '+';
    }
  };

  for (int i = 0; i < n; i++) {
    int j = i;
    while (j + 1 < n && (a[i] > 0) == (a[j + 1] > 0)) {
      j += 1;
    }
    Solve(i, j);
    i = j;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      ans[i] = ans[i + 1] = '+';
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ans[i];
    }
    cout << a[i];
  }
  cout << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}