#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory.h>
#include <algorithm>
#include <cassert>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fst first
#define snd second

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;

#define FNAME "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#endif

int n;
vi a;
vi p;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return 0;
  }
  a.resize(n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }
  p.resize(n);
  forn(i, n) {
    scanf("%d", &p[i]);
  }
  return 1;
}

const int B = 30;

inline bool bit(int mask, int i) {
  return (mask >> i) & 1;
}

struct node;
using nodePtr = node*;
struct node {
  nodePtr to[2];
  int size;
  int b;

  node(int b) : b(b) {
    memset (to, 0, sizeof to);
    size = 0;
  } 

  void upd() {
    size = 0;
    forn(c, 2) {
      if  (to[c]) {
        size += to[c]->size;
      }
    }
  }
};

void add(nodePtr& v, int val) {
  if  (v->b == -1) {
    ++v->size;
    return;
  }

  const int b = bit(val, v->b);
  if (!v->to[b]) {
    v->to[b] = new node(v->b - 1);
  }

  add(v->to[b], val);
  v->upd();
}

int select(nodePtr& v, int val) {
  assert(v->size > 0);
  if  (v->b == -1) {
    --v->size;
    return 0;
  }

  int b = bit(val, v->b);
  if  (!v->to[b] || v->to[b]->size == 0) {
    b ^= 1;
  } 
  assert(0 <= b && b <= 1);

//  eprintf("val=%d, v->b=%d, go to b=%d\n", val, v->b, b);

  assert(v->to[b] && v->to[b]->size > 0);
  int res = select(v->to[b], val);
  v->upd();
  assert(!bit(res, v->b));
  if  (b) {
    res ^= 1 << v->b;
  }
  return res;
}

void solve() {
  nodePtr root = new node(B - 1);
  for (int x : p) {
    add(root, x);
  }

  vi ans;
  for (int x : a) {
    int cur = select(root, x);
    ans.pb(cur ^ x);
  }

  for (int x : ans) {
    printf("%d ", x);
  }
  printf("\n\n");
}

int main() {
#ifdef LOCAL
  freopen(FNAME ".in", "r", stdin);
  freopen(FNAME ".out", "w", stdout);
#endif

  while (read()) {
    solve();

//    break;
  }

  return 0;
}