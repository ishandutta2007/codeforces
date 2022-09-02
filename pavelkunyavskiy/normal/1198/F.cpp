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

const int MAXN = 1e5;

int mind[MAXN];
vector<int> primes;

void gen_primes(int n) {
  mind[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (mind[i] == 0) {
      mind[i] = i;
      primes.push_back(i);
    }
    for (int j : primes) {
      if (j > mind[i] || i * j > n) break;
      mind[i * j] = j;
    }
  }
}

vector<int> a;
vector<int> tree;
int lst;
vector<int> ans;

int get(int l, int r) {
  int ans = 0;
  l += lst;
  r += lst;
  while (l < r) {
    if (l & 1) ans = __gcd(ans, tree[l++]);
    if (r & 1) ans = __gcd(ans, tree[--r]);
    l >>= 1;
    r >>= 1;
  }
  return ans;
}

vector<int> masks;
vector<vector<int>> nobit;

bool brute(int mask, int g2, int pos) {
  if (mask == 0 && __gcd(g2, get(pos, masks.size())) == 1) {
    return true;
  }
  int best = masks.size();
  for (int i = 0; i < (int)nobit.size(); i++) {
    const auto& nb = nobit[i];
    if (mask & (1 << i)) {
      auto it = lower_bound(nb.begin(), nb.end(), pos);
      if (it != nb.end()) {
        best = min(best, *it);
      }
    }
  }
  if (best == (int)masks.size()) {
    return false;
  }
  g2 = __gcd(g2, get(pos, best));
  if (!g2 || a[best] % g2 != 0) {
    if (brute(mask, __gcd(g2, a[best]), best + 1)) {
      return true;
    }
  }
  ans.push_back(best);
  if (brute(mask & masks[best], g2, best + 1)) {
    return true;
  }
  ans.pop_back();
  return false;
}

int main() {
#ifdef LOCAL
  freopen("f.in", "r", stdin);
  freopen("f.out", "w", stdout);
#endif
  gen_primes(MAXN - 1);

  auto factor = [](int x) {
    vector<int> ds;
    for (int j: primes) {
      if (j * j > x) break;
      if (x % j == 0) {
        ds.push_back(j);
      }
      while (x % j == 0) x /= j;
    }
    if (x != 1) ds.push_back(x);
    return ds;
  };

  int n;
  while (scanf("%d", &n) == 1) {
    a = vector<int>(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      auto ds = factor(a[i]);
      a[i] = 1;
      for (int x : ds) {
        a[i] *= x;
      }
    }

    vector<pair<int, int>> pos;
    pos.reserve(n);
    for (int i = 0; i < n; i++) {
      pos.emplace_back(a[i], i);
    }
    sort(pos.begin(), pos.end());
    for (int i = 0; i < n; i++) {
      a[i] = pos[i].first;
    }

    lst = 1;
    while (lst < n) {
      lst *= 2;
    }
    tree = vector<int>(2 * lst);
    for (int i = 0; i < n; i++) {
      tree[i + lst] = a[i];
    }
    for (int i = lst - 1; i > 0; i--) {
      tree[i] = __gcd(tree[2 * i], tree[2 * i + 1]);
    }

    ans.clear();

    vector<int> ds = factor(a[0]);
    ans.push_back(0);
    masks = vector<int>(n);
    nobit = vector<vector<int>>(ds.size());
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int) ds.size(); j++) {
        if (a[i] % ds[j] == 0) {
          masks[i] |= (1 << j);
        } else {
          nobit[j].push_back(i);
        }
      }
    }

    if (!brute(masks[0], 0, 1)) {
      printf("NO\n");
    } else {
      printf("YES\n");
      vector<int> res(n, 1);
      for (int x : ans) {
        res[pos[x].second] = 2;
      }
      for (int x : res) {
        printf("%d ", x);
      }
      printf("\n");
    }
  }

  return 0;
}