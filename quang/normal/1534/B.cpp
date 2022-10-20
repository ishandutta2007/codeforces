#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
int a[N];

void solve(int test) {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = a[n + 1] = 0;
  long long res = 0;
  for (int i = 0; i <= n; i++) {
    res += abs(a[i] - a[i + 1]);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      res -= min(a[i] - a[i - 1], a[i] - a[i + 1]);
      a[i] -= min(a[i] - a[i - 1], a[i] - a[i + 1]);
    }
  }
  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) {
    solve(test);  
  }
  return 0;
}