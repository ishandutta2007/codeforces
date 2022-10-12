#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m;

map<tuple<int, int, int, int, int, int>, int> memo;

int query;
int ask(int h, int w, int i1, int j1, int i2, int j2) {
  tuple<int, int, int, int, int, int> t = make_tuple(h, w, i1, j1, i2, j2);
  if (memo.find(t) != memo.end()) return memo[t];

  ++query;

  printf("? %d %d %d %d %d %d\n", h, w, i1, j1, i2, j2);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return memo[t] = ret;
}

vector<int> factorize(int n) {
  vector<int> ret;
  for (int p = 2; p*p <= n; ++p) {
    while (n % p == 0) {
      n /= p;
      ret.push_back(p);
    }
  }
  if (n > 1) ret.push_back(n);
  return ret;
}

int numdivisors(int n) {
  int ret = 0;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) ++ret;
  }
  return ret;
}

int solve() {
  scanf("%d %d", &n, &m);

  int r = n;
  for (int p : factorize(n)) {
    bool can = true;
    for (int step = 1; step < p; step *= 2) {
      if (step * 2 > p) {
        int gap = r / p * (p - step);
        if (!ask(gap, m, 1, 1, n - gap + 1, 1)) {
          can = false;
          break;
        }
      } else {
        int gap = r / p * step;
        if (!ask(gap, m, 1, 1, gap + 1, 1)) {
          can = false;
          break;
        }
      }
    }

    if (can) {
      r /= p;
    }
  }

  int c = m;
  for (int p : factorize(m)) {
    bool can = true;
    for (int step = 1; step < p; step *= 2) {
      if (step * 2 > p) {
        int gap = c / p * (p - step);
        if (!ask(n, gap, 1, 1, 1, m - gap + 1)) {
          can = false;
          break;
        }
      } else {
        int gap = c / p * step;
        if (!ask(n, gap, 1, 1, 1, gap + 1)) {
          can = false;
          break;
        }
      }
    }

    if (can) {
      c /= p;
    }
  }

  // cerr << query << endl;
  assert(query <= 3 * floor(log(n + m) / log(2)));

  printf("! %d\n", numdivisors(n/r) * numdivisors(m/c));
  fflush(stdout);
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