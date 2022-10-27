#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
char getc() { return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++); }
void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
void putc(char x) {
  *oS++ = x;
  if (oS == oT)
    flush();
}
template <class T> void read(T &x) {
  char ch;
  int f = 1;
  x = 0;
  while (isspace(ch = getc()))
    ;
  if (ch == '-')
    ch = getc(), f = -1;
  do
    x = x * 10 + (ch - '0');
  while (isdigit(ch = getc()));
  x *= f;
}
template <class T, class... A> void read(T &x, A &... args) {
  read(x);
  read(args...);
}
template <class T> void write(T x) {
  static char stk[128];
  int top = 0;
  if (x == 0) {
    putc('0');
    return;
  }
  if (x < 0)
    putc('-'), x = -x;
  while (x)
    stk[top++] = x % 10, x /= 10;
  while (top)
    putc(stk[--top] + '0');
}
template <class T, class... A> void write(T x, A... args) {
  write(x);
  putc(' ');
  write(args...);
}
void space() { putc(' '); }
void endl() { putc('\n'); }
struct _f {
  ~_f() { flush(); }
} __f;
} // namespace io
using io::endl;
using io::flush;
using io::getc;
using io::putc;
using io::read;
using io::space;
using io::write;

const int N = 300005;
int n;
bool u[N], v[N], gu[N];
bool ban[N];
struct pt {
  int x, y, c, id;
} a[N], b[N];

bool cmpx(pt i, pt j) { return i.x < j.x; }
bool cmpy(pt i, pt j) { return i.y < j.y; }

bool checkqwqx(int q, int _c) {
  static int sum[N][3];
  int c1 = 0, c2 = 1;
  if (_c == 0)
    c1 = 2;
  if (_c == 1)
    c2 = 2;

  /*memset(u, 0, sizeof u);
  int i = 1, s = 0;
  while (i <= n && s < q) {
    if (ban[a[i].id] == 0 && a[i].c == c1)
      s++, u[a[i].id] = 1;
    i++;
  }
  if (s == q) {
    i--;
    while (i < n && a[i + 1].x == a[i].x)
      i++;

    i++, s = 0;
    while (i <= n && s < q) {
      if (ban[a[i].id] == 0 && a[i].c == c2)
        s++, u[a[i].id] = 1;
      i++;
    }
    if (s == q)
      return 1;
  }

  swap(c1, c2);
  memset(u, 0, sizeof u);
  i = 1, s = 0;
  while (i <= n && s < q) {
    if (ban[a[i].id] == 0 && a[i].c == c1)
      s++, u[a[i].id] = 1;
    i++;
  }
  if (s == q) {
    i--;
    while (i < n && a[i + 1].x == a[i].x)
      i++;

    i++, s = 0;
    while (i <= n && s < q) {
      if (ban[a[i].id] == 0 && a[i].c == c2)
        s++, u[a[i].id] = 1;
      i++;
    }
    if (s == q)
      return 1;
  }
  return 0;*/

  memset(u, 0, sizeof u);
  for (int i = 1; i <= n; i++) {
    sum[i][0] = sum[i - 1][0];
    sum[i][1] = sum[i - 1][1];
    sum[i][2] = sum[i - 1][2];

    if (!ban[a[i].id])
      sum[i][a[i].c]++;
  }

  int i = q;
  while (i <= n && sum[i][c1] < q)
    i++;
  if (i <= n) {
    while (i < n && a[i + 1].x == a[i].x)
      i++;
    if (sum[n][c2] - sum[i][c2] >= q) {
      memset(u, 0, sizeof u);
      for (int i = 1;; i++) {
        if (ban[a[i].id] == 0 && a[i].c == c1)
          u[a[i].id] = 1;
        if (sum[i][c1] == q)
          break;
      }
      for (int i = n;; i--) {
        if (ban[a[i].id] == 0 && a[i].c == c2)
          u[a[i].id] = 1;
        if (sum[n][c2] - sum[i - 1][c2] == q)
          break;
      }
      return 1;
    }
  }

  swap(c1, c2);
  i = q;
  while (i <= n && sum[i][c1] < q)
    i++;
  if (i <= n) {
    while (i < n && a[i + 1].x == a[i].x)
      i++;
    if (sum[n][c2] - sum[i][c2] >= q) {
      memset(u, 0, sizeof u);
      for (int i = 1;; i++) {
        if (ban[a[i].id] == 0 && a[i].c == c1)
          u[a[i].id] = 1;
        if (sum[i][c1] == q)
          break;
      }
      for (int i = n;; i--) {
        if (ban[a[i].id] == 0 && a[i].c == c2)
          u[a[i].id] = 1;
        if (sum[n][c2] - sum[i - 1][c2] == q)
          break;
      }
      return 1;
    }
  }

  return 0;
}

bool checkqwqy(int q, int _c) {
  int c1 = 0, c2 = 1;
  if (_c == 0)
    c1 = 2;
  if (_c == 1)
    c2 = 2;
  memset(u, 0, sizeof u);
  int i = 1, s = 0;
  while (i <= n && s < q) {
    if (ban[b[i].id] == 0 && b[i].c == c1)
      s++, u[b[i].id] = 1;
    i++;
  }
  if (s == q) {
    i--;
    while (i < n && b[i + 1].y == b[i].y)
      i++;

    i++, s = 0;
    while (i <= n && s < q) {
      if (ban[b[i].id] == 0 && b[i].c == c2)
        s++, u[b[i].id] = 1;
      i++;
    }
    if (s == q)
      return 1;
  }

  swap(c1, c2);
  memset(u, 0, sizeof u);
  i = 1, s = 0;
  while (i <= n && s < q) {
    if (ban[b[i].id] == 0 && b[i].c == c1)
      s++, u[b[i].id] = 1;
    i++;
  }
  if (s == q) {
    i--;
    while (i < n && b[i + 1].y == b[i].y)
      i++;

    i++, s = 0;
    while (i <= n && s < q) {
      if (ban[b[i].id] == 0 && b[i].c == c2)
        s++, u[b[i].id] = 1;
      i++;
    }
    if (s == q)
      return 1;
  }
  return 0;
}

bool checkx(int q) {
  for (int cc = 0; cc < 3; cc++) {
    memset(v, 0, sizeof v);
    memset(ban, 0, sizeof ban);
    int s = 0, i = 1;
    while (s < q) {
      if (a[i].c == cc)
        s++, v[a[i].id] = 1;
      ban[a[i].id] = 1;
      i++;
    }
    i--;

    while (i < n && a[i + 1].x == a[i].x)
      i++, ban[a[i].id] = 1;

    if (2 * q > n - i)
      continue;

    if (checkqwqx(q, cc) || checkqwqy(q, cc))
      return 1;
  }

  for (int cc = 0; cc < 3; cc++) {
    memset(v, 0, sizeof v);
    memset(ban, 0, sizeof ban);
    int s = 0, i = n;
    while (s < q) {
      if (a[i].c == cc)
        s++, v[a[i].id] = 1;
      ban[a[i].id] = 1;
      i--;
    }
    i++;

    while (i > 1 && a[i - 1].x == a[i].x)
      i--, ban[a[i].id] = 1;

    if (2 * q > i - 1)
      continue;

    if (checkqwqy(q, cc))
      return 1;
  }
  return 0;
}

bool checky(int q) {
  for (int cc = 0; cc < 3; cc++) {
    memset(v, 0, sizeof v);
    memset(ban, 0, sizeof ban);
    int s = 0, i = 1;
    while (s < q) {
      if (b[i].c == cc)
        s++, v[b[i].id] = 1;
      ban[b[i].id] = 1;
      i++;
    }
    i--;

    while (i < n && b[i + 1].y == b[i].y)
      i++, ban[b[i].id] = 1;

    if (2 * q > n - i)
      continue;

    if (checkqwqx(q, cc) || checkqwqy(q, cc))
      return 1;
  }

  for (int cc = 0; cc < 3; cc++) {
    memset(v, 0, sizeof v);
    memset(ban, 0, sizeof ban);
    int s = 0, i = n;
    while (s < q) {
      if (b[i].c == cc)
        s++, v[b[i].id] = 1;
      ban[b[i].id] = 1;
      i--;
    }
    i++;

    while (i > 1 && b[i - 1].y == b[i].y)
      i--, ban[b[i].id] = 1;

    if (2 * q > i - 1)
      continue;

    if (checkqwqx(q, cc))
      return 1;
  }
  return 0;
}

int main() {
  read(n);
  for (int i = 1; i <= n; i++)
    read(a[i].x, a[i].y, a[i].c), a[i].c--, a[i].id = i, b[i] = a[i];

  sort(a + 1, a + n + 1, cmpx);
  sort(b + 1, b + n + 1, cmpy);
  int l = 1, r = n / 3, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (checkx(mid) || checky(mid)) {
      for (int i = 1; i <= n; i++)
        gu[i] = u[i] | v[i];
      ans = mid, l = mid + 1;
    } else
      r = mid - 1;
  }

  write(ans * 3);
}