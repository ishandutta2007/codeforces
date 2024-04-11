#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int lo = 0, hi = 2e9 + 1000;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      int cnt = mid - mid / n;
      if (cnt >= k) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    cout << hi << "\n";
  }  
}