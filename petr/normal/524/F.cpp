#include <bits/stdc++.h>

int const N = 2234567;
int const X = 33533;
long long M1;
long long M2;  // TODO TODO CHANGE
long long const MASK = (1LL << 32) - 1;

long long POW1[N], POW2[N];

int s[N];

int bal[N];

struct hash {
  long long h;
  int len;  
};

bool operator == (hash const & a, hash const & b) {
  return a.len == b.len && a.h == b.h;
}

hash OPEN[N], CLOSE[N], hs[N];

long long add1(long long h1, long long h2, int len2) {
  return (h1 * POW1[len2] + h2) % M1;
}

long long add2(long long h1, long long h2, int len2) {
  return (h1 * POW2[len2] + h2) % M2;
}

hash operator+ (hash const & a, hash const & b) {
  return {(add1(a.h >> 32, b.h >> 32, b.len) << 32) | add2(a.h & MASK, b.h & MASK, b.len), a.len + b.len};
}

int const TR = 1 << 21;
int const INF = 1 << 30;

int trmin[TR * 2];

void settree(int x, int y) {
  x += TR;
  trmin[x] = y;
  while (x > 1) {
    x >>= 1;
    if (trmin[x * 2] < trmin[x * 2 + 1]) trmin[x] = trmin[x * 2]; else
      trmin[x] = trmin[x * 2 + 1];
  }
}

int getmin(int left, int right) {
  --right;
  left += TR;
  right += TR;
  int ret = INF;
  while (left <= right) {
    if (left & 1) {
      if (ret > trmin[left]) ret = trmin[left];
      ++left;
    }
    if ((right & 1) == 0) {
      if (ret > trmin[right]) ret = trmin[right];
      --right;
    }
    left >>= 1;
    right >>= 1;
  }
  return ret;
}

struct answer {
  int addOpen;
  int pos;
  int addClose;
};

int n;

int getChar(answer const & f, int id) {
  if (id < f.addOpen) return '(';
  id -= f.addOpen;
  if (id < n) return s[f.pos + id];
  id -= n;
  if (id < f.addClose) return ')';
  //assert(false);
}

hash getHash(int left, int right) {
  long long h1 = hs[right - 1].h >> 32;
  long long h2 = hs[right - 1].h & MASK;
  long long g1 = hs[left - 1].h >> 32;
  long long g2 = hs[left - 1].h & MASK;
  h1 -= g1 * POW1[right - left] % M1;
  h2 -= g2 * POW2[right - left] % M2;
  if (h1 < 0) h1 += M1;
  if (h2 < 0) h2 += M2;
  return {(h1 << 32) | h2, right - left};
}

hash getHash(answer const & f, int len) {
  if (len <= f.addOpen) {
    return OPEN[len];
  }
  hash z = OPEN[f.addOpen];
  len -= f.addOpen;
  if (len <= n) {
    return z + getHash(f.pos, f.pos + len);
  }
  z = z + getHash(f.pos, f.pos + n);
  len -= n;
  if (len <= f.addClose) {
    return z + CLOSE[len];
  }
  assert(false);
}

bool operator < (answer const & f, answer const & g) {
  if (f.addOpen + f.addClose != g.addOpen + g.addClose) return f.addOpen + f.addClose < g.addOpen + g.addClose;
  int left = 0;
  int right = f.addOpen + f.addClose + n + 1;
  while (left < right - 1) {
    int mid = (left + right) >> 1;
    if (getHash(f, mid) == getHash(g, mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return getChar(f, left) < getChar(g, left);
}

std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
  
int const HALFBILLION = 500000000;

bool prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

void gen(long long & M) {
  M = rnd() % HALFBILLION + HALFBILLION;
  while (!prime(M)) {
    ++M;
  }
}

int main() {
  gen(M1);
  gen(M2);
  POW1[0] = POW2[0] = 1;
  OPEN[0] = {0, 0};
  CLOSE[0] = {0, 0};
  for (int i = 1; i < N; i++) {
    POW1[i] = POW1[i - 1] * X % M1;
    POW2[i] = POW2[i - 1] * X % M2;
    if (i == 1) {
      OPEN[i] = {(long long) '(', 1};
      CLOSE[i] = {(long long) ')', 1};
    } else {
      OPEN[i] = OPEN[i - 1] + OPEN[1];
      CLOSE[i] = CLOSE[i - 1] + CLOSE[1];
    }
  }
  int c = getchar();
  while (c <= 32) c = getchar();
  n = 1;
  while (c > 32) {
    s[n++] = c;
    c = getchar();
  }
  --n;
  for (int i = 1; i <= n; i++) s[i + n] = s[i];
  bal[0] = 0;
  for (int i = 1; i <= 2 * n; i++) {
    bal[i] = bal[i - 1] + (s[i] == '(' ? 1 : -1);
    settree(i, bal[i]);
  }
  hs[0] = {0, 0};
  for (int i = 1; i <= 2 * n; i++) {
    hash cur = {(long long) s[i], 1};
    hs[i] = hs[i - 1] + cur;
  }
  answer ans = {INF / 2, -1, INF / 2};
  for (int start = 1; start <= n; start++) {
    int minB = getmin(start - 1, start + n);
    int addOpen = bal[start - 1] - minB;
    int addClose = bal[start + n - 1] - minB;
    answer cur = {addOpen, start, addClose};
    if (cur < ans) ans = cur;
  }
  for (int i = 0; i < ans.addOpen; i++) putchar('(');
  for (int i = 0; i < n; i++) putchar(s[ans.pos + i]);
  for (int i = 0; i < ans.addClose; i++) putchar(')');
}