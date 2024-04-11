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
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i)
      cin >> h[i];
    int mx = 0;
    for (int x : h)
      mx = max(mx, x);
    long long left = -1, right = 1e18;
    while (right - left > 1) {
      long long mid = (left + right) / 2;
      long long cnt1 = (mid + 1) / 2;
      long long cnt2 = mid / 2;
      bool ok1 = true;
      for (int i = 0; i < n; ++i) {
        long long need = mx - h[i];
        long long kek = min(need / 2, cnt2);
        need -= kek * 2;
        cnt2 -= kek;
        if (need > cnt1) {
          ok1 = false;
          break;
        } else {
          cnt1 -= need;
        }
      }
      cnt1 = (mid + 1) / 2;
      cnt2 = mid / 2;
      bool ok2 = true;
      for (int i = 0; i < n; ++i) {
        long long need = mx + 1 - h[i];
        long long kek = min(need / 2, cnt2);
        need -= kek * 2;
        cnt2 -= kek;
        if (need > cnt1) {
          ok2 = false;
          break;
        } else {
          cnt1 -= need;
        }
      }
      if (ok1 || ok2)
        right = mid;
      else
        left = mid;
    }
    cout << right << '\n';
  }
  return 0;
}