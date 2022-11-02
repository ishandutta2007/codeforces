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

const int K = 18;
int hashes[K + 1][(1 << K) + 228];
pair<int, int> A[(1 << K) + 228];
pair<int, int> B[(1 << K) + 228];

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  int m = 1 << n;
  string s;
  cin >> s;
  for (int i = 0; i < m; ++i)
    hashes[0][i] = s[i] - 'a';
  for (int j = 1; j <= n; ++j) {
    for (int i = 0; i < m; ++i) {
      A[i] = make_pair(hashes[j - 1][i], hashes[j - 1][i ^ (1 << (j - 1))]);
      B[i] = A[i];
    }
    sort(B, B + m);
    for (int i = 0; i < m; ++i)
      hashes[j][i] = lower_bound(B, B + m, A[i]) - B;
  }
  int mn = 0;
  for (int i = 1; i < m; ++i) {
    int cur_mn = 0;
    for (int j = n - 1; j >= 0; --j) {
      int alpha = cur_mn ^ ((mn >> j) << j);
      int betta = cur_mn ^ ((i >> j) << j);
      if (hashes[j][alpha + (mn & ((1 << j) - 1))] == hashes[j][betta + (i & ((1 << j) - 1))])
        cur_mn += 1 << j;
    }
    if (s[cur_mn ^ i] < s[cur_mn ^ mn])
      mn = i;
  }
  for (int i = 0; i < m; ++i)
    cout << s[i ^ mn];
  cout << '\n';
  return 0;
}