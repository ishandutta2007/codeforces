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

const int N = 150010, INF = 1 << 30;

char s[N];
pair<int, pair<bool, int>> dp[N][5];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
      fill(dp[i], dp[i] + 5, make_pair(INF, make_pair(false, -1)));

      for (int j = 0; j < 5; ++j) {
        dp[i][j] = min(make_pair(dp[i - 1][j].first + 1, make_pair(true, j)), dp[i][j]);
      }
      if (s[i] == 'o') {
        for (int j = 0; j < 5; ++j)
          if (j != 4) {
            dp[i][1] = min(make_pair(dp[i - 1][j].first, make_pair(false, j)), dp[i][1]);
          }
      } else if (s[i] == 'n') {
        for (int j = 0; j < 5; ++j)
          if (j == 1) {
            dp[i][2] = min(make_pair(dp[i - 1][j].first, make_pair(false, j)), dp[i][2]);
          } else
            dp[i][0] = min(make_pair(dp[i - 1][j].first, make_pair(false, j)), dp[i][0]);
      } else if (s[i] == 'e') {
        for (int j = 0; j < 5; ++j)
          if (j != 2)
            dp[i][0] = min(make_pair(dp[i - 1][j].first, make_pair(false, j)), dp[i][0]);
      } else if (s[i] == 't') {
        for (int j = 0; j < 5; ++j)
          dp[i][3] = min(make_pair(dp[i - 1][j].first, make_pair(false, j)), dp[i][3]);
      } else if (s[i] == 'w') {
        for (int j = 0; j < 5; ++j)
          if (j == 3) {
            dp[i][4] = min(make_pair(dp[i - 1][j].first, make_pair(false, j)), dp[i][4]);
          } else
            dp[i][0] = min(make_pair(dp[i - 1][j].first, make_pair(false, j)), dp[i][0]);
      } else {
        for (int j = 0; j < 5; ++j)
          dp[i][0] = min(make_pair(dp[i - 1][j].first, make_pair(false, j)), dp[i][0]);
      }
    }
    int id = min_element(dp[n], dp[n] + 5) - dp[n];
    printf("%d\n", dp[n][id].first);
    for (int i = n; i; --i) {
      if (dp[i][id].second.first)
        printf("%d ", i);
      id = dp[i][id].second.second;
    }
    putchar('\n');
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}