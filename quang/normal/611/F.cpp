#include <bits/stdc++.h>

using namespace std;

const int N = 500010, MOD = 1000000007;

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

inline int mul(int u, int v) {
  return (long long) u * v % MOD;
}

int n, h, w;
char s[N];
vector <long long> dirx, diry;

void getx() {
  int curx = 0, maxx = 0, minx = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'R') {
      curx++;
      if (curx > maxx) {
        maxx = curx;
        dirx.push_back(i);
      }
    }
    if (s[i] == 'L') {
      curx--;
      if (curx < minx) {
        minx = curx;
        dirx.push_back(i);
      }
    }
  }
  vector <long long> foo;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'R') {
      curx++;
      if (curx > maxx) {
        maxx = curx;
        foo.push_back(i);
      }
    }
    if (s[i] == 'L') {
      curx--;
      if (curx < minx) {
        minx = curx;
        foo.push_back(i);
      }
    }
  }
  if (!foo.empty()) {
    int cur = 0;
    while (dirx.size() < w) {
      foo[cur] += n;
      dirx.push_back(foo[cur]);
      cur++;
      if (cur >= foo.size()) {
        cur = 0;
      }
    }
  }
}

void gety() {
  int cury = 0, maxy = 0, miny = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'U') {
      cury++;
      if (cury > maxy) {
        maxy = cury;
        diry.push_back(i);
      }
    }
    if (s[i] == 'D') {
      cury--;
      if (cury < miny) {
        miny = cury;
        diry.push_back(i);
      }
    }
  }
  vector <long long> foo;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'U') {
      cury++;
      if (cury > maxy) {
        maxy = cury;
        foo.push_back(i);
      }
    }
    if (s[i] == 'D') {
      cury--;
      if (cury < miny) {
        miny = cury;
        foo.push_back(i);
      }
    }
  }
  if (!foo.empty()) {
    int cur = 0;
    while (diry.size() < h) {
      foo[cur] += n;
      diry.push_back(foo[cur]);
      cur++;
      if (cur >= foo.size()) {
        cur = 0;
      }
    }
  }
}

void getres() {
  int res = 0;
  int curx = 0, cury = 0;
  while (curx < dirx.size() || cury < diry.size()) {
    if (!h || !w) {
      break;
    }
    int f = 0;
    if (cury == diry.size()) {
      f = 1;
    } else {
      if (curx < dirx.size()) {
        if (dirx[curx] < diry[cury]) {
          f = 1;
        }
      }
    }
    if (f) {
      res = add(res, mul(h, dirx[curx++] % MOD));
      w--;
    } else {
      res = add(res, mul(w, diry[cury++] % MOD));
      h--;
    }
  }
  if (h && w) {
    cout << -1 << endl;
  } else {
    cout << res << endl;
  }
}

int main() {
  scanf("%d %d %d", &n, &h, &w);
  scanf("%s", s + 1);
  getx();
  gety();
  getres();
    return 0;
}