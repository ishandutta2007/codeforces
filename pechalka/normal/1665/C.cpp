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
    vector<int> child_cnt(n);
    for (int i = 1; i < n; ++i) {
      int p;
      cin >> p;
      ++child_cnt[p - 1];
    }
    child_cnt.emplace_back(1);
    sort(child_cnt.rbegin(), child_cnt.rend());
    while (!child_cnt.empty() && child_cnt.back() == 0)
      child_cnt.pop_back();
    multiset<int> vals;
    for (int i = 0; i < child_cnt.size(); ++i)
      vals.emplace(child_cnt[i] + i);
    int k = child_cnt.size();
    while (*vals.rbegin() > k + 1) {
      int x = *(--vals.end());
      vals.erase(--vals.end());
      vals.emplace(x - 1);
      ++k;
    }
    cout << *(--vals.end()) << '\n';
  }
  return 0;
}