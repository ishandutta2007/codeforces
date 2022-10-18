#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; --i)
#define sz(c) ((int) (c).size())
#define pb push_back
#define all(c) begin(c), end(c)
#define next sljfdksdgfjksdj
#define prev fsldkjflksjflkdsjlk

typedef vector<int> vi;

const int INF = 1e9;

struct SegmTree {
  vi t;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;

    t.assign(sz * 2, INF);
  }

  void put(int pos, int val) {
    int v = sz + pos;
    t[v] = val;
    v /= 2;
    while (v) {
      t[v] = min(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  int get_min(int l, int r) {
    l += sz;
    r += sz;
    int res = INF;
    while (l <= r) {
      res = min(res, t[l]);
      res = min(res, t[r]);
      l = (l + 1) / 2;
      r = (r - 1) / 2;
    }
    return res;            
  }
};

SegmTree T;
vi prev;
vi next;
vi coord;
vector<vi> positions;
vi a;
int n;

int compress(int x) {
  return lower_bound(all(coord), x) - coord.begin();
}                     

int decompress(int x) {
  return coord[x];
}

int get_cnt(int l, int r, int val) {
  return upper_bound(all(positions[val]), r) - lower_bound(all(positions[val]), l);
}

void precalc() {
  sort(all(coord));
  coord.resize(unique(all(coord)) - coord.begin());

  forn(i, n) {
    a[i] = compress(a[i]);
  }

  vi last(sz(coord), -1);
  prev = vi(n, -1);
  forn(i, n) {
    prev[i] = last[a[i]];
    last[a[i]] = i;
  }

  last = vi(sz(coord), -1);
  next = vi(n, -1);
  ford(i, n) {
    next[i] = last[a[i]];
    last[a[i]] = i;
  }
  
  positions.resize(sz(coord));
  forn(i, n) {
    positions[a[i]].pb(i);
  }
}           

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
#endif

  scanf("%d", &n);
  a.assign(n, 0);
  forn(i, n) {
    scanf("%d", &a[i]);
    coord.pb(a[i]);
  }

  precalc();

  vi b;
  T = SegmTree(n);
  int b1 = -1;
  int b2 = -1;
  int end_pos = n;
  int prev_end_pos = -1;
  forn(i, n) {
    if  (get_cnt(prev_end_pos + 1, i, a[i]) >= 4) {
      forn(j, 4) b.pb(a[i]);
      prev_end_pos = i;
      end_pos = n;
    } else if  (i == end_pos) {
      b.pb(b1);
      b.pb(b2);
      b.pb(b1);
      b.pb(b2);
      prev_end_pos = i;
      end_pos = n;
    } else if  (prev[i] > prev_end_pos) {
      int l = prev[i] + 1;
      int r = i - 1;
      int pos = T.get_min(l, r);

      if  (pos < end_pos) {
        b1 = a[i];
        b2 = a[pos];
        end_pos = pos;
      }
    }

    if  (prev[i] != -1) {
      T.put(prev[i], INF);
    }
    if  (next[i] != -1) {
      T.put(i, next[i]);
    }
  }

  printf("%d\n", sz(b));
  forn(i, sz(b)) {
    printf("%d ", decompress(b[i]));
  }

  return 0;
}