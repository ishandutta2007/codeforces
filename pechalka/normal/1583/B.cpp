#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <bitset>
#include <random>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

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
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      ++cnt[b - 1];
    }
    int root = 0;
    while (cnt[root])
      ++root;
    for (int i = 0; i < root; ++i)
      cout << i + 1 << ' ' << root + 1 << '\n';
    for (int i = root + 1; i < n; ++i)
      cout << i + 1 << ' ' << root + 1 << '\n';
  }
  return 0;
}