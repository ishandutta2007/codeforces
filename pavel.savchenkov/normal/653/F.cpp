#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const int MAXN = 5e5 + 10;
const int INF = 1e9;

struct SegmTree {
  vii t;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;

    t.assign(sz * 2, mp(INF, 0));
  }

  void put(int pos, int val) {
    int v = sz + pos;
    t[v] = mp(val, pos);
    v /= 2;
    while (v) {
      t[v] = min(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  int left_less(int v, int tl, int tr, int l, int r, int val) {
    l = max(l, tl);
    r = min(r, tr);
    if  (l > r) {
      return MAXN;
    }
    if  (t[v].fst >= val) {
      return MAXN;
    }
    if  (tl == tr) {
      return tl;
    }
    int tm = (tl + tr) >> 1;
    int left = left_less(v * 2, tl, tm, l, r, val);
    if  (left < MAXN) return left;
    return left_less(v * 2 + 1, tm + 1, tr, l, r, val);
  }

  int left_less(int l, int r, int val) {
    return left_less(1, 0, sz - 1, l, r, val);
  }
};

vi suff_arr(string s) {
  char mx = *max_element(all(s));
  s += mx + 1;
  const int n = sz(s);
  vi c(n);
  vi p(n);
  vi np(n);

  vi cnt(max(n, 300), 0);
  for (char c : s) {
    ++cnt[c];  
  }
  forn(i, sz(cnt) - 1) {
    cnt[i + 1] += cnt[i];
  }
  forn(i, n) {
    p[--cnt[s[i]]] = i;
  }

  int cls = 0;
  forn(i, n) {
    if  (i == 0 || s[p[i]] != s[p[i - 1]]) {
      c[p[i]] = cls++;
    } else {
      c[p[i]] = c[p[i - 1]];
    }
  }
  
  for (int len = 2; len/2 <= n && cls < n; len *= 2) {
    cnt.assign(sz(cnt), 0);
    forn(i, n) {
      ++cnt[c[i]];
    } 
    forn(i, sz(cnt) - 1) {
      cnt[i + 1] += cnt[i];
    }
    forn(i, n) {
      np[--cnt[c[(i + len/2) % n]]] = i;
    }

    cnt.assign(sz(cnt), 0);
    forn(i, n) {
      ++cnt[c[i]];
    }
    forn(i, sz(cnt) - 1) {
      cnt[i + 1] += cnt[i];
    }
    ford(i, n) {
      int j = np[i];
      p[--cnt[c[j]]] = j;
    }
    
    vi nc(sz(c));
    cls = 0;
    forn(i, n) {
      if  (i == 0) {
        nc[p[i]] = cls++;
        continue;
      }
      if  (c[p[i]] != c[p[i - 1]] || c[(p[i] + len/2) % n] != c[(p[i - 1] + len/2) % n]) {
        nc[p[i]] = cls++;
      } else {
        nc[p[i]] = nc[p[i - 1]];
      }
    } 

    c.swap(nc);
  }

  return p;
}

vi brut_suff_arr(const string& s) {
  const int n = sz(s);
  vi p(n);
  iota(all(p), 0);
  sort(all(p), [&](int i, int j) { return s.substr(i, sz(s) - i) < s.substr(j, sz(s) - j); });
  return p;
}

void check_suff_arr() {
  while (1) {
    int n = 5;
    string s;
    forn(i, n) s += 'a' + rand() % 5;
    s += '$';
    ++n;
    vi my_p = suff_arr(s);
    vi p = brut_suff_arr(s);
    if  (my_p != p) {
      printf("Fail %s\n", s.c_str());
      printf("My:\n");
      forn(i, n) {
        printf("%s\n", s.substr(my_p[i], sz(s) - my_p[i]).c_str());
      }
      puts("");
      printf("Correct:\n");
      forn(i, n) {
        printf("%s\n", s.substr(p[i], sz(s) - p[i]).c_str());
      }
      return;
    }
    cerr << "OK n = " << n << endl;
  }
}

string s;
int n;

bool read() {
  if  (scanf("%d\n", &n) < 1) {
    return false;
  }
  static char buf[MAXN];
  gets(buf);
  s = string(buf);
  return true;
}

int bal[MAXN];
SegmTree T;
vi poses[MAXN * 2];

void precalc() {
  bal[0] = 0;
  forn(i, n) {
    int cur = (s[i] == '(') ? +1 : -1;
    bal[i + 1] = bal[i] + cur;
  }
  forn(i, n + 1) {
    poses[MAXN + bal[i]].pb(i);
  } 

  T = SegmTree(n + 1);
  forn(i, n + 1) {
    T.put(i, bal[i]);
  }
}

int get_cnt(int l, int r, int val) {
  if  (l > r) return 0;
  return upper_bound(all(poses[MAXN + val]), r) - lower_bound(all(poses[MAXN + val]), l);
}

int calc(int i, int lower) {
  int j = T.left_less(i, n - 1, bal[i]);
  int upper = j - i;
  
  int l = max(i, i + lower - 1);
  int r = i + upper - 1;
  return get_cnt(l + 1, r + 1, bal[i]);
}

ll solve() {
  precalc();

  vi p = suff_arr(s);
  vi lcp(n, 0);
  vi pos(n, -1);
  forn(i, n) pos[p[i]] = i;

  int len = 0;
  forn(i, n) {
    int j = pos[i];
    if  (j == n - 1) {
      continue;
    }
    len = max(0, len - 1);
    while (i + len < n && p[j + 1] + len < n && s[i + len] == s[p[j + 1] + len]) ++len;
    lcp[i] = len;
  } 

  ll ans = 0;
  forn(i, n) {
    int start = p[i];
    int lower = (i == 0) ? 0 : lcp[p[i - 1]] + 1;
    int cur = calc(start, lower);
    ans += cur;
  }
  return ans;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  //freopen(FILE_NAME ".out", "w", stdout);
#endif

//  check_suff_arr();

  while (read()) {
    printf("%I64d\n", solve());
  //  break;
  }

#ifdef DEBUG
  cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}