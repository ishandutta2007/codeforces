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

int k;

bool read() {
  if (scanf("%d", &k) < 1) {
    return false;
  }
  k++;
  return true;
}

string ans;
int cur;

void add(int x, int y) {
  ans += (char) ('a' + x);
  ans += (char) ('1' + y);
  ans += ' ';
  cur++;
}

void solve() {
  ans.clear();
  cur = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 8; j++) {
      add(j, 2 * i);
      if (cur + 2 == k) {
        if (j == 7) {
          add(7, 6);
          add(7, 7);
        } else {
          add(j, 7);
          add(7, 7);
        }
        printf("%s\n", ans.c_str());
        return;
      }
    }
    for (int j = 7; j >= 0; j--) {
      add(j, 2 * i + 1);
      if (cur + 2 == k) {
        if (j == 7) {
          add(7, 6);
          add(7, 7);
        } else {
          add(j, 7);
          add(7, 7);
        }
        printf("%s\n", ans.c_str());
        return;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int it = 0; it < 4; it++) {
      int x = ((it & 2) ? 2 * i + 1 : 2 * i);
      int y = (it == 1 || it == 2 ? 7 : 6);
      add(x, y);
      if (cur + 2 == k) {
        if (y == 7) {
          add(6, 7);
          add(7, 7);
        } else {
          add(7, y);
          add(7, 7);
        }
        printf("%s\n", ans.c_str());
        return;
      }
    }
  }
  if (k == 64) {
    add(7, 6);
  }
  add(6, 6);
  add(6, 7);
  add(7, 7);
  printf("%s\n", ans.c_str());
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