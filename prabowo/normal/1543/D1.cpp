#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, k;

int ask(int y) {
  printf("%d\n", y);
  fflush(stdout);
  int r;
  scanf("%d", &r);
  if (r == -1) assert(0);
  return r;
}

vector<int> digs(int x) {
  vector<int> ret(20);
  for (int i = 0; i < 20; ++i) {
    ret[i] = x % k;
    x /= k;
  }
  return ret;
}

int subs(vector<int> a, vector<int> b) {
  int ret = 0, mul = 1;
  for (int i = 0; i < 20; ++i) {
    a[i] -= b[i];
    if (a[i] < 0) a[i] += k;
    ret += mul * a[i];
    mul *= k;
  }
  return ret;
}

int solve() {
  scanf("%d %d", &n, &k);

  if (ask(0) == 1) return 0;

  for (int i = 1; i < n; ++i) {
    vector<int> prv = digs(i - 1);
    vector<int> cur = digs(i);

    if (!(i & 1)) {
      if (ask(subs(cur, prv)) == 1) return 0;
    } else {
      if (ask(subs(prv, cur)) == 1) return 0;
    }
  }
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}