#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, d;
int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int cur = 1;
  long long res = 0;
  for (int i = 3; i <= n; i++) {
    while (a[cur] + d < a[i]) {
      cur++;
    }
    if (i - cur >= 2) {
      res += 1ll * (i - cur) * (i - cur - 1) / 2;
    }
  }
  cout << res << endl;
  return 0;
}