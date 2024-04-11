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

struct myset {
  set<pair<ll, int>> s;
  map<int, ll> val;
  ll add_all;
public:

  void add_to_all(ll x) {
    add_all += x;
  }

  void insert(int pos, ll x) {
    x -= add_all;
    val[pos] = x;
    s.insert({x, pos});
  }

  ll get_max() {
    if (s.empty()) {
      return 0;
    }
    return s.rbegin()->first + add_all;
  }

  void add_one(int pos, ll x) {
    s.erase({val[pos], pos});
    val[pos] += x;
    s.insert({val[pos], pos});
  }

  pair<ll, int> pop_max() {
    if (s.empty()) {
      return {0, -1};
    }
    auto res = *s.rbegin();
    erase(res.second);
    res.first += add_all;
    return res;
  }

  void erase(int pos) {
    s.erase({val[pos], pos});
    val.erase(pos);
  }
};

void solve(int n, ll c) {
  myset tot;
  myset have;

  vector<int> v(2 * n - 1);

  for (int &x : v) {
    scanf("%d", &x);
  }

  ll res = 0;

  for (int i = 0; i < n; i++) {
    if (i) {
      have.add_to_all(v[2 * i - 1]);
      tot.add_to_all(v[2 * i - 1]);
    }
    have.insert(i, 0);
    tot.insert(i, 0);
    have.add_to_all(v[2 * i]);
    tot.add_to_all(v[2 * i]);

    vector<int> limited;
    while (have.get_max() >= c) {
      pair<ll, int> v = have.pop_max();
      tot.add_one(v.second, c - v.first);
      limited.push_back(v.second);
    }

    ll cur = tot.get_max();
    tot.add_to_all(-cur);
    res += cur;

    for (int pos: limited) {
      tot.erase(pos);
    }
  }

  printf("%lld\n", res);
}

int main() {
#ifdef LOCAL
  freopen("f.in", "r", stdin);
  freopen("f.out", "w", stdout);
#endif

  int n;
  ll c;
  while (scanf("%d%lld", &n, &c) == 2) {
    solve(n, c);
  }

  return 0;
}