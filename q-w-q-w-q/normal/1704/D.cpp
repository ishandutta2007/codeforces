#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, m;

void solve() {
  cin >> n >> m;
  long long mn = 1ll << 60, mx = 0;
  int p = 0;
  for (int i = 1; i <= n; i++) {
    long long s = 0;
    for (int j = 1; j <= m; j++) {
      long long x;
      cin >> x;
      s += x * j;
    }
    if (s < mn)
      mn = s;
    if (s > mx)
      mx = s, p = i;
  }
  cout << p << ' ' << mx - mn << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}

//mod mwr!!!!