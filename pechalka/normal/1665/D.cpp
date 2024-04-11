#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#ifdef DEBUG
int x;

int ask(int a, int b) {
  a += x, b += x;
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
#else
int ask(int a, int b) {
  cout << '?' << ' ' << a << ' ' << b << endl;
  int ans;
  cin >> ans;
  return ans;
}
#endif


int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int t;
  cin >> t;
  while (t--) {
#ifdef DEBUG
    x = 1e9;
    cout << x << endl;
#endif
    int ans = 0;
    for (int k = 1; k <= 30; ++k) {
      int m = 1 << k;
      int kk = ask(m / 2 - ans, m / 2 - ans + m);
      if (kk == m)
        ans += m / 2;
    }
    cout << '!' << ' ' << ans << endl;
  }
  return 0;
}