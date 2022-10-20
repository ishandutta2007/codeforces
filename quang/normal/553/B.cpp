#include <bits/stdc++.h>

using namespace std;

int n;
long long k;
long long f[60];
int res[60];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  f[0] = f[1] = 1;
  for (int i = 2; i <= 50; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }
  k--;
  for (int i = 1; i <= n; i++) {
    if (k >= f[n - i]) {
      res[i] = i + 1;
      res[i + 1] = i;
      k -= f[n - i];
      i++;
    } else {
      res[i] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
  return 0;
}