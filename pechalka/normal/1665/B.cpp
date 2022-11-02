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
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
      cin >> A[i];
    sort(A.begin(), A.end());
    int cnt = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (i && A[i] != A[i - 1])
        cur = 1;
      else
        ++cur;
      cnt = max(cnt, cur);
    }
    int ans = 0;
    while (cnt < n) {
      ++ans;
      ans += min(cnt, n - cnt);
      cnt += min(cnt, n - cnt);
    }
    cout << ans << '\n';
  }
  return 0;
}