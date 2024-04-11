#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  const int M = 1e6;
  vector<int> prime(M, 1);
  for (int i = 2; i < M; i++) {
    if (!prime[i]) continue;
    for (int j = i + i; j < M; j += i) {
      prime[j] = 0;
    }
  }

  int T = 1;
  cin >> T;
  while (T--) {
    int d;
    cin >> d;
    int p = 1 + d;
    while (!prime[p]) p++;
    int q = p + d;
    while (!prime[q]) q++;
    cout << 1ll * p * q << '\n';
  }
  return 0;
}