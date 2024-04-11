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

const int MAXN = 1000'100;
char field[MAXN];
int dp1[MAXN];
int dp2[MAXN];

const int K = 20;
int lg[MAXN];
int table[MAXN][K];

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  lg[0] = -1;
  for (int i = 1; i < MAXN; ++i)
    lg[i] = lg[i / 2] + 1;

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n * m; ++i)
    cin >> field[i];
  for (int i = 0; i < m; ++i)
    table[i][0] = -1;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (field[i * m + j - 1] == 'X' && field[(i - 1) * m + j] == 'X')
        table[j][0] = j;
    }
  }
  for (int j = 1; j < K; ++j) {
    for (int i = 0; i + (1 << j) <= m; ++i)
      table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    int k = lg[r - l];
    int val = max(table[l][k], table[r - (1 << k)][k]);
    if (l < val)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}