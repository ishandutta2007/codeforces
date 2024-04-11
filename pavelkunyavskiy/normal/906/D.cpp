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
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

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

int phi(int n) {
  int res = 1;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      res *= i - 1;
      n /= i;
      while (n % i == 0) {
        res *= i;
        n /= i;
      }
    }
  }
  if (n != 1) {
    res *= n - 1;
  }
  return res;
}

ll my_mod(ll x, int m) {
  ll MAGIC = (100000 / m + 1) * m;
  if (x >= MAGIC) {
    return MAGIC + (x % m);
  }
  return x;
}

ll my_mul(ll a, ll b, int m) {
  return my_mod((a * 1LL * b), m);
}

ll bin_pow(ll a, ll b, int x) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res = my_mul(a, res, x);
    }
    a = my_mul(a, a, x);
    b >>= 1;
  }
  return res;
}

int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> p;
  p.push_back(m);
  while (p.back() != 1) {
    p.push_back(phi(p.back()));
  }
  for (int i = 0; i < 20; i++) {
    p.push_back(1);
  }
  vector<int> w(n);
  vector<int> ones;
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
    if (w[i] == 1) {
      ones.push_back(i);
    }
  }

  int q;
  scanf("%d", &q);
  for (int _ = 0; _ < q; _++) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l;
    --r;
    int next_one_pos = lower_bound(ones.begin(), ones.end(), l) - ones.begin();
    if (next_one_pos != (int)ones.size()) {
      r = min(r, ones[next_one_pos] - 1);
    }
    r = min(r, l + (int)p.size() - 1);
    ll x = 1;
    for (int i = r; i >= l; i--) {
      x = bin_pow(w[i], x, p[i - l]);
    }
    printf("%d\n", (int)(x % m));
  }

  return 0;
}