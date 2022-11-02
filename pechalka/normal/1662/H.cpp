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

int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

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
    int w, l;
    cin >> w >> l;
    set<int> ans;
    ans.emplace(1);
    ans.emplace(2);
    int x = gcd(w - 1, l - 1);
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        ans.emplace(i);
        ans.emplace(x / i);
      }
    }
    x = gcd(w - 2, l);
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        ans.emplace(i);
        ans.emplace(x / i);
      }
    }
    x = gcd(w, l - 2);
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        ans.emplace(i);
        ans.emplace(x / i);
      }
    }
    cout << ans.size() << ' ';
    for (int y : ans)
      cout << y << ' ';
    cout << '\n';
  }
  return 0;
}