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

const ll INF = 1LL << 60;

struct sumSet {
  multiset<int> s;
  ll sum;

  void insert(int a) {
    s.insert(a);
    sum += a;
  }

  bool erase(int a) {
    auto it = s.find(a);
    if (it == s.end()) return false;
    s.erase(it);
    sum -= a;
    return true;
  }

  ll big() {
    return s.size() ? *s.rbegin() : -INF;
  }

  ll small() {
    return s.size() ? *s.begin() : INF;
  }

  int pop_big() {
    int res = *s.rbegin();
    s.erase(--s.end());
    sum -= res;
    return res;
  }

  int pop_small() {
    int res = *s.begin();
    s.erase(s.begin());
    sum -= res;
    return res;
  }


  int count() {
    return (int) s.size();
  }
};

sumSet other_used;
sumSet other_not_used;

ll calc(int need, int got, ll got_sum) {
  need -= got;
  if (need < 0) {
    return INF;
  }
  if (need > other_used.count() + other_not_used.count()) {
    return INF;
  }
  while (other_used.count() > need) {
    other_not_used.insert(other_used.pop_big());
  }
  while (other_used.count() < need) {
    other_used.insert(other_not_used.pop_small());
  }
  while (other_used.big() > other_not_used.small()) {
    other_not_used.insert(other_used.pop_big());
    other_used.insert(other_not_used.pop_small());
  }
  return got_sum + other_used.sum;
}

int main() {
#ifdef LOCAL
  freopen("e.in", "r", stdin);
  freopen("e.out", "w", stdout);
#endif

  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  vector<int> c(n);
  for (int& x : c) {
    scanf("%d", &x);
  }
  vector<int> mask(n);
  for (int i = 1; i <= 2; i *= 2) {
    int cnt;
    scanf("%d", &cnt);
    for (int j = 0; j < cnt; j++) {
      int a;
      scanf("%d", &a);
      mask[a - 1] |= i;
    }
  }

  vector<int> v[4];

  for (int i = 0; i < n; i++) {
    v[mask[i]].push_back(c[i]);
  }

  for (int i = 0; i < 4; i++) {
    sort(v[i].begin(), v[i].end());
  }

  int min_both = max(0, k - min((int)v[1].size(), (int)v[2].size()));

  if (min_both > (int)v[3].size()) {
    printf("-1\n");
    return 0;
  }

  for (int x : v[0]) {
    other_used.insert(x);
  }

  for (int i = 1; i <= 2; i *= 2) {
    for (int j = k - min_both; j < (int)v[i].size(); j++) {
      other_used.insert(v[i][j]);
    }
  }

  ll sum = 0;
  for (int i = 0; i < k - min_both; i++) {
    sum += v[1][i] + v[2][i];
  }
  for (int i = 0; i < min_both; i++) {
    sum += v[3][i];
  }
  for (int i = min_both; i < (int)v[3].size(); i++) {
    other_used.insert(v[3][i]);
  }

  ll ans = calc(m, 2 * k - min_both, sum);

//  eprintf("%d %d %zd\n", min_both, k, v[3].size());
  for (int i = min_both + 1; i <= k && i <= (int)v[3].size(); i++) {
    sum += v[3][i - 1];
    sum -= v[1][k - i] + v[2][k - i];
    other_used.insert(v[1][k - i]);
    other_used.insert(v[2][k - i]);
    if (!other_used.erase(v[3][i - 1])) {
      assert(other_not_used.erase(v[3][i - 1]));
    }

    ans = min(ans, calc(m, 2 * k - i, sum));
  }

  if (ans == INF) {
    printf("-1\n");
  } else {
    printf("%lld\n", ans);
  }

  return 0;
}