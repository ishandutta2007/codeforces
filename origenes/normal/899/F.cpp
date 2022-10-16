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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 212345;

int fen[maxn], n, m;
set<int> lis[256];
bool vis[maxn];
char s[maxn], ans[maxn];

inline int lowbit(int x) {
  return x & -x;
}

void inc(int x) {
  while (x <= n) {
    fen[x]++;
    x += lowbit(x);
  }
}

int sum(int x) {
  int ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

int get(int x) {
  int lo = x, hi = n;
  while (lo <= hi) {
    int mid = lo + hi >> 1, rm = sum(mid);
    if (mid - rm == x && !vis[mid]) return mid;
    if (mid - rm >= x) hi = mid - 1;
    else lo = mid + 1;
  }
}

int main() {
  scanf("%d%d%s", &n, &m, s + 1);
  FOR(i, 1, n) lis[s[i]].insert(i);
  while (m--) {
    int l, r;
    char now[3];
    scanf("%d%d%s", &l, &r, now);
    l = get(l), r = get(r);
    int cur = now[0];
    auto it = lis[cur].lower_bound(l);
    if (it == lis[cur].end()) continue;
    auto en = lis[cur].lower_bound(r + 1);
    vector<int> pos;
    while (it != en) {
      pos.eb(*it);
      it++;
    }
    for (auto u : pos) {
      vis[u] = true;
      inc(u);
      lis[cur].erase(u);
    }
  }
  REP(i, 256) for (auto now : lis[i]) ans[now] = i;
  FOR(i, 1, n) if (ans[i]) putchar(ans[i]);
}