#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

string s[N];
int bins[N];
string digits[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int bindigits[10];

int conv(string s) {
  int ret = 0;
  for (int i = 0; i < 7; ++i) {
    if (s[i] == '1') ret |= 1 << i;
  }
  return ret;
}

int n, k;
int dp[N][N];

int cache[N][N];
int needed(int x, int y) {
  if (cache[x][y] != -100) return cache[x][y];
  int ret = 0;
  for (int i = 0; i < 7; ++i) {
    int s = (x >> i & 1);
    int t = (y >> i & 1);
    if (s == t) continue;
    if (s == 1 && t == 0) return cache[x][y] = -1;
    ++ret;
  }
  return cache[x][y] = ret;
}

int f(int x, int y) {
  if (y < 0) return 0;
  if (x == n) return y == 0 ? 1 : 0;
  if (~dp[x][y]) return dp[x][y];

  int ret = 0;
  for (int k = 0; k <= 9; ++k) {
    int need = needed(bins[x], bindigits[k]);
    if (need >= 0) ret |= f(x+1, y - need);
  }

  return dp[x][y] = ret;
}

int solve() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    bins[i] = conv(s[i]);
  }

  for (int i = 0; i < 128; ++i) for (int j = 0; j < 128; ++j) cache[i][j] = -100;

  for (int k = 0; k <= 9; ++k) {
    bindigits[k] = conv(digits[k]);
  }

  memset(dp, -1, sizeof dp);


  if (f(0, k) == 0) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 9; j >= 0; --j) {
      int need = needed(bins[i], bindigits[j]);
      if (need >= 0 && f(i+1, k - need) == 1) {
        k -= need;
        cout << j;
        break;
      }
    }
  }

  cout << endl;
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}