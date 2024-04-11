#include <bits/stdc++.h>
using namespace std;

const int M = 1e7 + 5;
int f[M];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  iota(f, f + M, 0);
  for (int i = 2; i < M; i++) {
    if (f[i] == i) {
      for (int j = 2 * i; j < M; j += i) {
        f[j] = min(f[j], i);
      }
    }
  }
  
  int n;
  cin >> n;
  vector<array<int, 2>> ans(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int aa = a;
    vector<int> d = {f[a]};
    int ff = f[a];
    while (a % ff == 0) {
      a /= ff;
    }
    d.emplace_back(a);
    ans[i][0] = ans[i][1] = -1;
    if (d[0] == 1 || d[1] == 1) continue;
    if (__gcd(d[0] + d[1], aa) == 1) {
      ans[i][0] = d[0];
      ans[i][1] = d[1];
    }
  }

  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < n; i++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}