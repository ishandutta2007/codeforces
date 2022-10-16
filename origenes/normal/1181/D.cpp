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

const int maxn = 512345;

int n, m, q;
int cnt[maxn], ans[maxn], nxt[maxn], fen[maxn];
pair<ll, int> query[maxn];
vector<int> G[maxn];

inline int lowbit(int x) {
  return x & -x;
}

void add(int x) {
  while (x <= m) {
    fen[x]++;
    x += lowbit(x);
  }
}

int sum(int x) {
  int ret = 0;
  while (x) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

void comb(const vector<int> &tab) {
  for (auto it : tab) add(it);
}

int get(int rk) {
  int lo = 1, hi = m;
  while (lo < hi) {
    int mi = lo + hi >> 1, tmp = sum(mi);
    if (tmp > rk) hi = mi - 1;
    else if (tmp == rk) hi = mi;
    else lo = mi + 1;
  }
  return lo;
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  FOR(i, 1, n) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  FOR(i, 1, m) G[cnt[i]].eb(i);
  nxt[n] = -1;
  ROF(i, n - 1, 0) nxt[i] = G[i + 1].empty() ? nxt[i + 1] : i + 1;
  FOR(i, 1, q) {
    query[i]._2 = i;
    scanf("%lld", &query[i]._1);
    query[i]._1 -= n;
  }
  sort(query + 1, query + q + 1);
  int j = 0;
  while (G[j].empty()) j++;
  comb(G[j]);
  ll st = 1, en = nxt[j] == -1 ? -1 : (nxt[j] - j) * ll(G[j].size());
  int go = 1, tot = G[j].size();
  FOR(i, 1, q) {
    while (en != -1 && en < query[i]._1) {
      st = en + 1;
      j = nxt[j];
      tot += G[j].size();
      en = nxt[j] == -1 ? -1 : st + (nxt[j] - j) * ll(tot) - 1;
      comb(G[j]);
    }
    if (en == -1) {
      go = i;
      break;
    }
    ans[query[i]._2] = get((query[i]._1 - st) % tot + 1);
    go = i + 1;
  }
  FOR(i, go, q) ans[query[i]._2] = (query[i]._1 - st) % m + 1;
  FOR(i, 1, q) printf("%d\n", ans[i]);
}