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

const int N = 1010;
pair<int, int> a[N];
int q[N];
bool g[N][N];
char ans[N][N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1, greater<pair<int, int>>());
  int p = 1;
  while (a[p].first >= p)
    ++p;
  --p;
  for (int i = 1; i <= p; ++i) {
    for (int j = 1; j <= i; ++j)
      g[i][j] = true;
    for (int j = i + 1; j <= a[i].first; ++j)
      g[i][j + 1] = true;
  }
  for (int i = p + 1; i <= n; ++i) {
    for (int j = 2; j <= a[i].first; ++j)
      g[i][j] = true;
    g[i][i + 1] = true;
  }
  for (int i = 1; i <= n; ++i)
    q[a[i].second] = i;
  for (int i = 1; i <= n + 1; ++i)
    for (int j = 1; j <= n; ++j)
      ans[i][j] = g[q[j]][i] + '0';
  printf("%d\n", n + 1);
  for (int i = 1; i <= n + 1; ++i)
    puts(ans[i] + 1);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}