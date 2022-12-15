#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, base;
int xorBase(int a, int b) {
  if (!a)
    return b;
  return (a + b) % base + base * xorBase(a / base, b / base);
}
int invBase(int a) {
  if (!a)
    return 0;
  return (base - a % base) % base + base * invBase(a / base);
}

void solve() {
  cin >> n >> base;
  int curChange = 0;
  for (int i = 0; i < n; ++i)
    assert(xorBase(invBase(i), i) == 0);

  for (int i = 0; i < n; ++i) {
    int ask = xorBase(i % 2 ? invBase(i) : i, curChange);
    cout << ask << endl;
    int ret;
    cin >> ret;
    if (ret == 1)
      return;
    curChange = xorBase(invBase(curChange), ask);
  }
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}