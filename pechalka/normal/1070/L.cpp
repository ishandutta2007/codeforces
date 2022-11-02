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

bitset<2000> A[2000];
bitset<2000> id[2000];
vector<int> G[2000];

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
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      G[a - 1].emplace_back(b - 1);
      G[b - 1].emplace_back(a - 1);
    }
    bitset<2000> need;
    for (int i = 0; i < n; ++i)
      need[i] = (G[i].size() % 2);
    for (int i = 0; i < n; ++i) {
      A[i].reset();
      id[i].reset();
      for (int j : G[i])
        A[i][j] = 1;
      if (G[i].size() % 2)
        A[i][i] = 1;
      id[i][i] = 1;
      G[i].clear();
    }
    if (need.none()) {
      cout << 1 << '\n';
      for (int i = 0; i < n; ++i)
        cout << 1 << ' ';
      cout << '\n';
      continue;
    }
    vector<int> kekes(n);
    int last = 0;
    for (int i = 0; i < n; ++i) {
      int j = last;
      while (j < n && !A[j][i])
        ++j;
      if (j == n)
        continue;
      swap(A[j], A[last]);
      swap(id[j], id[last]);
      for (int j = last + 1; j < n; ++j) {
        if (A[j][i]) {
          A[j] ^= A[last];
          id[j] ^= id[last];
        }
      }
      kekes[last] = i;
      ++last;
    }

    bitset<2000> ans;
    for (int i = 0; i < last; ++i) {
      if (need[kekes[i]]) {
        need ^= A[i];
        ans ^= id[i];
      }
    }
    cout << 2 << '\n';
    for (int i = 0; i < n; ++i)
      cout << int(ans[i]) + 1 << ' ';
    cout << '\n';
  }
  return 0;
}