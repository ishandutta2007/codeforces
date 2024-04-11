#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void solve() {
  int a = -1, b = -1;
  {
    vector<int> pr;
    int x = n;
    for (int d = 2; d * d <= x; d++) {
      if (!(x % d)) {
        pr.push_back(d);
        while (!(x % d)) {
          x /= d;
        }
      }
    }
    if (x > 1) {
      pr.push_back(x);
    }
    if (sz(pr) <= 1) {
      printf("NO\n");
      return;
    }
    a = pr[0];
    b = pr[1];
  }
  pair<int, int> p = gcd(a, b);
  long long x = p.first, y = p.second;
  x *= n - 1;
  y *= n - 1;
  if (y < 0) {
    swap(a, b);
    swap(x, y);
  }
  if (x < 0) {
    assert(y > 0);
    long long k = (-x + b - 1) / b;
    x += k * b;
    y -= k * a;
  }
  assert(x > 0);
  assert(y > 0);
  printf("YES\n");
  printf("2\n");
  printf("%d %d\n", (int) x, n / a);
  printf("%d %d\n", (int) y, n / b);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}