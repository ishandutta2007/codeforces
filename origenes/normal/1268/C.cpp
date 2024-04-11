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

const int maxn = 212345;

inline int lowbit(int x) {
  return x & -x;
}

int n;

void add(ll *fen, int x, int d) {
  while (x <= n) {
    fen[x] += d;
    x += lowbit(x);
  }
}

ll query(const ll *fen, int x) {
  ll ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

int p[maxn], pos[maxn];
ll f[maxn], g[maxn], ans[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", p + i);
  FOR(i, 1, n) pos[p[i]] = i;
  ROF(i, n, 1) {
    ans[p[i]] = query(f, p[i]);
    add(f, p[i], 1);
  }
  reset(f, 0);
  set<int> s;
  s.emplace(pos[1]);
  int need = 1, have = pos[1];
  add(f, pos[1], 1); add(g, pos[1], pos[1]);
  putchar('0');
  FOR(i, 2, n) {
    s.emplace(pos[i]);
    if (pos[i] < have) need++;
    auto it = s.lower_bound(have);
    int mn = i / 2 + 1, mx = mn;
    if (i % 2 == 0) mn--;
    while (need < mn) it++, need++;
    while (need > mx) it--, need--;
    have = *it;
    add(f, pos[i], 1); add(g, pos[i], pos[i]);
    ll cl = query(f, have - 1), sl = query(g, have - 1);
    ll cr = query(f, n) - query(f, have), sr = query(g, n) - query(g, have);
    ll shift = sr - cr * have + cl * have - sl;
    shift -= need * ll(need - 1) / 2 + (i - need) * ll(i - need + 1) / 2;
    ans[i] += ans[i - 1];
    printf(" %lld", ans[i] + shift);
  }
}