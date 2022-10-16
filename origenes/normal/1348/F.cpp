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
const int inf = 0x3f3f3f3f;

inline int lowbit(int x) {
  return x & -x;
}

int n;
int fen[maxn], id[maxn], l[maxn], r[maxn], ans[maxn];
vector<pii> G[maxn];

void upd(int x, int v) {
  while (x <= n) {
    chkmin(fen[x], v);
    x += lowbit(x);
  }
}

int query(int x) {
  int ret = inf;
  while (x > 0) {
    chkmin(ret, fen[x]);
    x -= lowbit(x);
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d%d", l + i, r + i);
    G[l[i]].eb(r[i], i);
  }
  set<pii> s;
  FOR(i, 1, n) {
    for (auto _ : G[i]) s.emplace(_);
    if (!s.empty() && s.begin()->_1 >= i) {
      ans[s.begin()->_2] = i;
      id[i] = s.begin()->_2;
      s.erase(s.begin());
    }
  }
  reset(fen, 0x3f);
  ROF(i, n, 1) {
    if (query(r[id[i]]) <= i) FOR(j, i + 1, n) if (l[id[j]] <= i) {
      puts("NO");
      FOR(k, 1, n) printf("%d ", ans[k]);
      putchar('\n');
      swap(ans[id[i]], ans[id[j]]);
      FOR(k, 1, n) printf("%d ", ans[k]);
      return 0;
    }
    upd(i, l[id[i]]);
  }
  puts("YES");
  FOR(i, 1, n) printf("%d ", ans[i]);
}