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
const int MOD = 1e9 + 7;

int n, m;
pii fen[maxn * 2];

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int lowbit(int x) {
  return x & -x;
}

void add(pii &a, pii b) {
  if (a._1 > b._1) a = b;
  else if (a._1 == b._1) a._2 = add(a._2, b._2);
}

void add(int x, pii v) {
  while (x <= m) {
    add(fen[x], v);
    x += lowbit(x);
  }
}

pii query(int x) {
  pii ret = {MOD, 0};
  while (x > 0) {
    add(ret, fen[x]);
    x -= lowbit(x);
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  vector<int> val{-1, 0};
  vector<pii> tab(n);
  REP(i, n) {
    scanf("%d%d", &tab[i]._2, &tab[i]._1);
    val.eb(tab[i]._1);
    val.eb(tab[i]._2);
  }
  sort(all(val));
  uni(val);
  sort(all(tab));
  pii ans = {MOD, 0};
  m = val.size();
  FOR(i, 1, m) fen[i] = ans;
  add(1, {0, 1});
  for (auto now : tab) {
    int x = lower_bound(all(val), now._1) - val.begin();
    int y = lower_bound(all(val), now._2) - val.begin();
    auto cur = query(x);
    if (now._2 > tab.back()._1) add(ans, {cur._1 + now._1, cur._2});
    else add(y, {now._1 + cur._1 - now._2, cur._2});
  }
  printf("%d", ans._2);
}