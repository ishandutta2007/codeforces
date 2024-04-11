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
#include <functional>

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

const int MAXN = 1e5 + 10;

#define TEST 0

char s[MAXN];
char t[MAXN];
int n, m;

struct query {
  int ls, rs;
  int lt, rt;

  void read() {
#if TEST
    ls = rand() % n;
    rs = rand() % n;
    if  (ls > rs) {
      swap(ls, rs);
    }
    lt = rand() % m;
    rt = rand() % m;
    if  (lt > rt) {
      swap(lt, rt);
    }
    return;
#endif

    scanf("%d%d%d%d", &ls, &rs, &lt, &rt);
    --ls;
    --rs;
    --lt;
    --rt;
  }
};

vector<query> qs;

bool read() {
#if !TEST
  scanf("\n%s\n", s);
  n = strlen(s);
  scanf("%s\n", t);
  m = strlen(t);
#else
  n = 1 + rand() % 5;
  m = 1 + rand() % 5;
  forn(i, n) {
    s[i] = 'A' + rand() % 3;
  }
  forn(i, m) {
    t[i] = 'A' + rand() % 3;
  }
#endif

  int q;
#if !TEST
  if  (scanf("%d", &q) < 1) {
    return 0;
  }
#else
  q = 1 + rand() % 10;
#endif

  eprintf("s = %s\nt = %s\n", s, t);

  qs.resize(q);
  forn(i, q) {
    qs[i].read();
  }
  return 1;
}

vi pos_s;
vi pos_t;
vi suff_a_s;
vi suff_a_t;

void precalc(vi& suff_a, vi& pos, char* str, int len) {
  pos.clear();
  forn(i, len) {
    if  (str[i] != 'A') {
      pos.pb(i);
    }
  }

  suff_a.resize(len);
  forn(i, len) {
    if  (str[i] != 'A') {
      suff_a[i] = 0;
    } else {
      suff_a[i] = (i > 0 ? suff_a[i - 1] : 0) + 1; 
    }
  }
}

int get_cnt(const vi& pos, int l, int r) {
  l = lower_bound(all(pos), l) - pos.begin();
  r = upper_bound(all(pos), r) - pos.begin();
  return r - l;
}

bool ask(const query& q) {
  int cnt_b_s = get_cnt(pos_s, q.ls, q.rs);
  int cnt_b_t = get_cnt(pos_t, q.lt, q.rt);

  const int len_qt = q.rt - q.lt + 1;
  const int len_qs = q.rs - q.ls + 1;

  if  (cnt_b_t == 0) {
    if  (cnt_b_s != 0) {
      return 0;
    }
    return len_qs >= len_qt && len_qs % 3 == len_qt % 3;
  }

  assert(len_qt >= 1);
  assert(len_qs >= 1);

  int a_s = min(len_qs, suff_a_s[q.rs]);
  int a_t = min(len_qt, suff_a_t[q.rt]);

  if  (a_s < a_t) {
    return 0;
  } 

  if  (a_s == a_t) {
    if  (cnt_b_s == 0) {
      return 0;
    }
  }

  if  (a_s > a_t) {
    if  (a_s % 3 != a_t % 3 || cnt_b_s == 0) {
      cnt_b_s += 2;
    }
  }

  int rest = cnt_b_t - cnt_b_s;
  return rest >= 0 && rest % 2 == 0;
}

bool brut_ask(const query& q) {
  string ss;
  for (int i = q.ls; i <= q.rs; ++i) {
    ss += s[i];
  }
  string tt;
  for (int i = q.lt; i <= q.rt; ++i) {
    tt += t[i];
  }

  map<char, string> to;
  for (char ch = 'A'; ch <= 'C'; ++ch) {
    string cur;
    for (char c = 'A'; c <= 'C'; ++c) {
      if  (c != ch) {
        cur += c;
      }
    }
    to[ch] = cur;
  }

  set<string> was;
  bool ok = 0;
  function<void(string)> rec = [&](string cur) {
    if  (ok) {
      return;
    }
    eprintf("cur = %s\n", cur.data());
    if  (cur == tt) {
      ok = 1;
      return;
    }
    if  (sz(cur) > max(sz(ss), sz(tt)) * 2) {
      return;
    }

    forn(i, sz(cur)) {
      string nw = cur.substr(0, i);
      nw += to[cur[i]];
      nw += cur.substr(i + 1, sz(cur) - i - 1);
      assert(sz(nw) == sz(cur) + 1);
      rec(nw);
    }

    forn(i, sz(cur) - 2) {
      if  (cur[i] == 'A' && cur[i + 1] == 'A' && cur[i + 2] == 'A') {
        string nw = cur.substr(0, i);
        if  (i + 3 < sz(cur))
        nw += cur.substr(i + 3, sz(cur) - (i + 3));
        rec(nw);
      }
    }
  };

  rec(ss);
  return ok;
}

void solve() {
  precalc(suff_a_s, pos_s, s, n);
  precalc(suff_a_t, pos_t, t, m);

  for (const auto& q : qs) {
    bool res = ask(q);
    putchar(res ? '1' : '0');

#if TEST
    bool br = brut_ask(q);
    if  (br != res) {
      eprintf("s=%s, t=%s, t[%d, %d], s[%d, %d]\n", s, t, q.lt, q.rt, q.ls, q.rs);
      eprintf("my=%d, br=%d\n", res, br);
      exit(0);
    } else {
      eprintf("OK %d == %d\n", res, br);
    }
#endif
  }
  puts("");
}

int main() {
#ifdef LOCAL
  freopen(FNAME ".in", "r", stdin);
  freopen(FNAME ".out", "w", stdout);
#endif

  while (read()) {
    solve();
  }

  return 0;
}