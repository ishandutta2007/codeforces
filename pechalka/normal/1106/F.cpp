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

const int P = 998244353;
const int K = 31596;

pair<int, int> gcd_extended(int a, int b) {
  if (b == 0) {
    return make_pair(1, 0);
  }
  auto tmp = gcd_extended(b, a % b);
  return make_pair(tmp.second, tmp.first - (a / b) * tmp.second);
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

  int k;
  cin >> k;
  vector<int> b(k);
  for (int i = 0; i < k; ++i)
    cin >> b[i];
  int n, m;
  cin >> n >> m;
  int c;
  {
    //matrix power
    vector<vector<int>> A(k, vector<int>(k, 0));
    for (int i = 0; i < k - 1; ++i)
      A[i + 1][i] = 1;
    for (int i = 0; i < k; ++i)
      A[i][k - 1] = b[k - 1 - i];
    vector<vector<int>> ans(k, vector<int>(k, 0));
    for (int i = 0; i < k; ++i)
      ans[i][i] = 1;
    vector<vector<int>> tmp(k, vector<int>(k, 0));
    int power = n - k;
    while (power) {
      if (power & 1) {
        for (int i = 0; i < k; ++i) {
          for (int l = 0; l < k; ++l) {
            tmp[i][l] = 0;
            for (int j = 0; j < k; j += 1)
              tmp[i][l] = (tmp[i][l] + A[i][j] * 1ll * ans[j][l]) % (P - 1);
          }
        }
        swap(ans, tmp);
      }
      power >>= 1;
      for (int i = 0; i < k; ++i) {
        for (int l = 0; l < k; ++l) {
          tmp[i][l] = 0;
          for (int j = 0; j < k; j += 1)
            tmp[i][l] = (tmp[i][l] + A[i][j] * 1ll * A[j][l]) % (P - 1);
        }
      }
      swap(A, tmp);
    }
    c = ans[k - 1][k - 1];
  }
  const int G = 3;
  int d;
  {
    //discrete log
    map<int, int> vals;
    int pw = 1;
    for (int i = 0; i < K; i += 1) {
      vals[m * 1ll * pw % P] = i;
      pw = pw * 1ll * G % P;
    }
    int x = 1;
    for (int j = 1; j <= K; j += 1) {
      x = x * 1ll * pw % P;
      if (vals.count(x)) {
        d = j * K - vals[x];
        break;
      }
    }
  }
  //solve cX + (P-1)Y = d;
  auto tmp = gcd_extended(c, P - 1);
  int l = (c * tmp.first + (P - 1) * tmp.second);
  if (d % l != 0) {
    cout << -1 << '\n';
    return 0;
  }
  int deg = tmp.first * 1ll * (d / l) % (P - 1);
  if (deg < 0) {
    deg += P - 1;
  }
  int cur = G;
  int ans = 1;
  while (deg) {
    if (deg & 1)
      ans = ans * 1ll * cur % P;
    deg >>= 1;
    cur = cur * 1ll * cur % P;
  }
  cout << ans << '\n';
  return 0;
}