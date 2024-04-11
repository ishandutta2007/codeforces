#include <cstdio>
#include <iostream>

using namespace std;

int n, d;

void solve() {
  cin >> n >> d;
  int ans = 0, l = 0, r = 2e9;
  while (n--) {
    int x;
    cin >> x;
    int a = x - d, b = x + d;
    if (b < l || a > r) {
      ans++;
      l = a, r = b;
    } else
      l = max(l, a), r = min(r, b);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}

//mod mwr!!!