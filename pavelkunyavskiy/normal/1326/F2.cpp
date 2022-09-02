#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

using namespace std;

#ifdef LOCAL
static struct __timestamper {
  string what;
  __timestamper(const char* what) : what(what){};
  __timestamper(const string& what) : what(what){};
  ~__timestamper(){
    TIMESTAMPf("%s", what.data());
  }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

void transform(vector<ll>& x) {
  int n = __builtin_ctz(x.size());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      if (j & (1 << i)) {
        x[j] += x[j ^ (1 << i)];
      }
    }
  }
}

void untransform(vector<ll>& x) {
  int n = __builtin_ctz(x.size());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      if (j & (1 << i)) {
        x[j] -= x[j ^ (1 << i)];
      }
    }
  }
}

void inverse(vector<ll>& x) {
  int n = __builtin_ctz(x.size());
  for (int i = 0; i < (1 << n); i++){
    int y = ((1 << n) - 1) ^ i;
    if (i < y) {
      swap(x[i], x[y]);
    }
  }
}


void gen_splits(int n, vector<vector<int>>& res, vector<int> cur) {
  if (n == 0) {
    res.push_back(cur);
    return;
  }
  for (int i = !cur.empty() ? cur.back() : 1; i <= n; i++) {
    cur.push_back(i);
    gen_splits(n - i, res, cur);
    cur.pop_back();
  }
}


int main() {
#ifdef LOCAL
  freopen("f2.in", "r", stdin);
  freopen("f2.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char c;
        scanf(" %c", &c);
        g[i][j] = c == '1';
      }
    }

    vector<vector<ll>> dp(n, vector<ll>(1 << n));
    for (int i = 0; i < n; i++) {
      dp[i][1 << i] = 1;
    }

    for (int i = 1; i < (1 << n); i++) {
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          for (int k = 0; k < n; k++) {
            if (!(i & (1 << k))) {
              if (g[j][k]) {
                dp[k][i | (1 << k)] += dp[j][i];
              }
            }
          }
        }
      }
    }

    vector<vector<ll>> ans(n + 1, vector<ll>(1 << n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (1 << n); j++) {
        ans[__builtin_popcount(j)][j] += dp[i][j];
      }
    }

    eprintf("%lld\n",ans.back().back());
    for (auto &x : ans) {
      transform(x);
    }

    vector<vector<int>> splits;
    gen_splits(n, splits, vector<int>());

    map<vector<int>, ll> prec;

    vector<int> coef(1 << n);
    for (int i = 0; i < (int)(1 << n); i++) {
      coef[i] = (__builtin_parity(i) == (n % 2)) ? 1 : -1;
    }

    for (const auto &split : splits) {
      ll tot = 0;
      for (int i = 0; i < (1 << n); i++) {
        ll cur = 1;
        for (int s : split) {
          cur *= ans[s][i];
        }
        tot += cur * coef[i];
      }
//      for (int x : split)
//        eprintf("%d ", x);
//      eprintf(": cur = %lld\n", tot);
      assert(tot >= 0);
      prec[split] = tot;
    }

    vector<ll> result(1 << (n - 1));

    for (int i = 0; i < (1 << (n - 1)); i++) {
      vector<int> split;
      split.push_back(1);
      for (int j = 0; j < (n - 1); j++) {
        if (i & (1 << j)) {
          split.back()++;
        } else {
          split.push_back(1);
        }
      }
      sort(split.begin(), split.end());
      assert(prec.count(split));
      result[i] = prec[split];
    }

    inverse(result);
    untransform(result);
    inverse(result);

    for (ll x : result) {
      printf("%lld ", x);
    }
    printf("\n");
  }


  return 0;
}