#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 312345;
const int inf = 0x3f3f3f3f;

struct Seg {
  int l, r, val;
} T[maxn << 2];

int t, n;
int a[maxn], b[maxn];
queue<int> pos[maxn];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l == r) T[o].val = a[l];
  else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    T[o].val = min(T[o << 1].val, T[o << 1 | 1].val);
  }
}

int query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].val;
  int mi = T[o].l + T[o].r >> 1, ret = inf;
  if (l <= mi) chkmin(ret, query(o << 1, l, r));
  if (r > mi) chkmin(ret, query(o << 1 | 1, l, r));
  return ret;
}

void update(int o, int x) {
  if (T[o].l == T[o].r) T[o].val = inf;
  else {
    int mi = T[o].l + T[o].r >> 1;
    if (x <= mi) update(o << 1, x);
    else update(o << 1 | 1, x);
    T[o].val = min(T[o << 1].val, T[o << 1 | 1].val);
  }
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", a + i);
    FOR(i, 1, n) scanf("%d", b + i);
    vector<int> aa(a + 1, a + n + 1), bb(b + 1, b + n + 1);
    sort(all(aa)); sort(all(bb));
    if (aa != bb) {
      puts("NO");
      continue;
    }
    FOR(i, 1, n) while (!pos[i].empty()) pos[i].pop();
    FOR(i, 1, n) pos[a[i]].emplace(i);
    build(1, 1, n);
    bool good = true;
    FOR(i, 1, n) {
      int en = pos[b[i]].front(); pos[b[i]].pop();
      int ret = query(1, 1, en);
      if (ret < b[i]) {
        good = false;
        break;
      }
      update(1, en);
    }
    puts(good ? "YES" : "NO");
  }
}