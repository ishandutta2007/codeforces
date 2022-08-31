// http://yosupo06.github.io/Algorithm/src/base.hpp

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#ifdef LOCAL

ostream& operator<<(ostream& os, __int128_t x) {
  if (x < 0) {
    os << "-";
    x *= -1;
  }
  if (x == 0) {
    return os << "0";
  }
  string s;
  while (x) {
    s += char(x % 10 + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return os << s;
}
ostream& operator<<(ostream& os, __uint128_t x) {
  if (x == 0) {
    return os << "0";
  }
  string s;
  while (x) {
    s += char(x % 10 + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return os << s;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p);
template <class T>
ostream& operator<<(ostream& os, const V<T>& v);
template <class T>
ostream& operator<<(ostream& os, const deque<T>& v);
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a);
template <class T>
ostream& operator<<(ostream& os, const set<T>& s);
template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& m);

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T>
ostream& operator<<(ostream& os, const V<T>& v) {
  os << "[";
  bool f = false;
  for (auto d : v) {
    if (f) os << ", ";
    f = true;
    os << d;
  }
  return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, const deque<T>& v) {
  os << "[";
  bool f = false;
  for (auto d : v) {
    if (f) os << ", ";
    f = true;
    os << d;
  }
  return os << "]";
}
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a) {
  os << "[";
  bool f = false;
  for (auto d : a) {
    if (f) os << ", ";
    f = true;
    os << d;
  }
  return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  bool f = false;
  for (auto d : s) {
    if (f) os << ", ";
    f = true;
    os << d;
  }
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, const multiset<T>& s) {
  os << "{";
  bool f = false;
  for (auto d : s) {
    if (f) os << ", ";
    f = true;
    os << d;
  }
  return os << "}";
}

template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& s) {
  os << "{";
  bool f = false;
  for (auto p : s) {
    if (f) os << ", ";
    f = true;
    os << p.first << ": " << p.second;
  }
  return os << "}";
}

struct PrettyOS {
  ostream& os;
  bool first;

  template <class T>
  auto operator<<(T&& x) {
    if (!first) os << ", ";
    first = false;
    os << x;
    return *this;
  }
};
template <class... T>
void dbg0(T&&... t) {
  (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                        \
  do {                                                  \
    cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
    dbg0(__VA_ARGS__);                                  \
    cerr << endl;                                       \
  } while (false);
#else
#define dbg(...)
#endif

// http://yosupo06.github.io/Algorithm/src/util/fast_io.hpp

#include <unistd.h>

struct Scanner {
  int fd = -1;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, stdin);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T& ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T& ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) {
      ref = 10 * ref + (line[st++] & 0xf);
    }
    if (neg) ref = -ref;
    return true;
  }
  template <class T>
  bool read_single(V<T>& ref) {
    for (auto& d : ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  void read() {}
  template <class H, class... T>
  void read(H& h, T&... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE* fp) : fd(fileno(fp)) {}
};

struct Printer {
 public:
  template <bool F = false>
  void write() {}
  template <bool F = false, class H, class... T>
  void write(const H& h, const T&... t) {
    if (F) write_single(' ');
    write_single(h);
    write<true>(t...);
  }
  template <class... T>
  void writeln(const T&... t) {
    write(t...);
    write_single('\n');
  }

  Printer(FILE* _fp) : fp(_fp) {}
  ~Printer() { flush(); }

 private:
  static constexpr size_t SIZE = 1 << 15;
  FILE* fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write_single(const char& val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write_single(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write_single('0');
      return;
    }
    if (val < 0) {
      write_single('-');
      val = -val;  // todo min
    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) {
      line[pos + i] = small[len - 1 - i];
    }
    pos += len;
  }
  void write_single(const string& s) {
    for (char c : s) write_single(c);
  }
  void write_single(const char* s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write_single(s[i]);
  }
  template <class T>
  void write_single(const V<T>& val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write_single(' ');
      write_single(val[i]);
    }
  }
};

Scanner sc{stdin};
Printer pr{stdout};
V<int> dx{1, 0, -1, 0};
V<int> dy{0, 1, 0, -1};

void q() {
  int N = 0;
  sc.read(N);
  VV<ll> a(N, V<ll>(N));
  for (auto& x : a) {
    for (auto& v : x) sc.read(v);
  }

  ll ans = 0;
  VV<int> nuru(N, V<int>(N));

  auto done = [&](int i, int j) {
    for (int k = 0; k < 4; k++) {
      int ni = i + dx[k];
      int nj = j + dy[k];
      if (0 <= min(ni, nj) and max(ni, nj) < N) {
        nuru[ni][nj] ^= 1;
      }
    }
    ans ^= a[i][j];
  };

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == 0) {
        continue;
      }
      if (nuru[i - 1][j] == 0) done(i, j);
    }
  }

  pr.writeln(ans);
}

int main() {
  int T = 1;
  sc.read(T);
  while (T--) q();
}