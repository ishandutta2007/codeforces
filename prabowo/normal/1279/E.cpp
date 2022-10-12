#include <bits/stdc++.h>
using namespace std;

const int N = 55;

const long long INFLL = 2000000000000000000LL;

long long dp[N];
long long fact[N];

long long mul(long long x, long long y) {
  if ((long double) x * y > INFLL) return INFLL;
  return x * y;
}

long long f(int n) {
  if (n == 0) return 1;
  if (~dp[n]) return dp[n];

  long long ret = 0;
  for (int i = n-1; i >= 0; --i) {
    ret = min(ret + mul(fact[n-i-2], f(i)), INFLL);
  }

  return dp[n] = ret;
}

namespace Choose {
  int chosen[N];
  int par[N];
  void init(int n) {
    for (int i = 0; i < n; ++i) {
      chosen[i] = -1;
      par[i] = i;
    }
  }

  int root(int u) {
    if (u == par[u]) return u;
    return par[u] = root(par[u]);
  }

  int take(int x, int k) {
    for (int i = 0; ; ++i) {
      if (chosen[i] >= 0) continue;
      if (root(x) == root(i)) continue;

      if (k-- == 0) {
        par[root(x)] = root(i);
        chosen[i] = 1;
        return i;
      }
    }
  }

  int notChosen() {
    for (int i = 0; ; ++i) {
      if (chosen[i] == -1) return i;
    }
  }
}

int solve() {  
  int n; long long k;
  scanf("%d %lld", &n, &k);
  --k;

  vector<pair<int, long long>> ans;
  for (int i = 0; i < n;) {
    int j;

    for (j = i+1; j < n; ++j) {
      if (mul(f(n-j), fact[j-i-2]) <= k) {
        k -= mul(f(n-j), fact[j-i-2]);
      } else {
        break;
      }
    }

    if (j == n && k >= fact[j-i-2]) return 0 * printf("-1\n");

    ans.emplace_back(j-i-2, k / f(n-j));
    k -= f(n-j) * ans.back().second;
    i = j;
  }

  int cur = 0;
  for (pair<int, long long> u: ans) {
    // cerr << "asdf: " << u.first << " " << u.second << endl;

    printf("%d ", u.first + cur + 2);

    if (u.first >= 0) {
      Choose::init(u.first + 1);

      for (int i = 0; i < u.first; ++i) {
        int k = u.first - i - 1;
        int x = 0;
        while (fact[k] <= u.second) {
          u.second -= fact[k];
          ++x;
        }

        printf("%d ", cur + Choose::take(i+1, x) + 1);
      }
      printf("%d ", Choose::notChosen() + cur + 1);
    }

    cur += u.first + 2;
  }
  printf("\n");

  return 0;
}

void init() {
  memset(dp, -1, sizeof dp);
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = mul(fact[i-1], i);
  }
  fact[-1] = 1;
}

int main() {
  init();
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}