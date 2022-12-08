#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int N = 2010, P = 1000000007;

int n, m;
int f[N][N], g[N][N], xc[N][N], yc[N][N];
int sf[N][N], sg[N][N];
char s[N][N];

void add(int &x, int y) {
  if ((x += y) >= P)
    x -= P;
}

void sub(int&x , int y) {
  if ((x -= y) < 0)
    x += P;
}

int norm(int x) { return x >= P ? (x - P) : x; }

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> (s[i] + 1);
  if (n == 1 && m == 1) {
    cout << "1\n";
    return 0;
  }
  for (int i = n; i; --i)
    for (int j = m; j; --j) {
      xc[i][j] = xc[i + 1][j] + (s[i + 1][j] == 'R');
      yc[i][j] = yc[i][j + 1] + (s[i][j + 1] == 'R');
    }
  f[n][m] = 1;
  g[n][m] = 1;
  sf[n][m] = sg[n][m] = 1;
  for (int i = n; i; --i)
    for (int j = m; j; --j) {
      if (i == n && j == m)
        continue;
      f[i][j] = norm(sg[i + 1][j] + P - sg[n - xc[i][j] + 1][j]);
      g[i][j] = norm(sf[i][j + 1] + P - sf[i][m - yc[i][j] + 1]);
      sf[i][j] = norm(f[i][j] + sf[i][j + 1]);
      sg[i][j] = norm(g[i][j] + sg[i + 1][j]);
    }
  cout << norm(f[1][1] + g[1][1]) << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}