#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

lint Power(lint n, lint x) {
  lint res = 1;
  for (; x > 0; x /= 2, n = 1ll * n * n % MOD) {
    if (x & 1) {
      res = 1ll * res * n % MOD;
    }
  }
  return res;
}

void Main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(101);
  vector<int> b(101);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x] = 1;
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    b[x] = 1;
  }
  int cnt = 0;
  for (int i = 1; i <= 100; i++) {
    if (a[i] && b[i]) {
      cnt += 1;
    }
  }
  cout << cnt << '\n';
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