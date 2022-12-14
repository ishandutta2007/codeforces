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

const int maxn = 112345;

int n, m;
int par[maxn];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

int main() {
  scanf("%d%d", &n, &m);
  int st, en, ans;
  scanf("%d%d%d", &st, &en, &ans);
  vector<pair<int, pii>> edges(m - 1);
  for (auto &e : edges) scanf("%d%d%d", &e._2._1, &e._2._2, &e._1);
  sort(all(edges));
  iota(par + 1, par + n + 1, 1);
  ans = 1e9;
  for (auto e : edges) {
    int u = Find(e._2._1), v = Find(e._2._2), w = e._1;
    if (u == v) continue;
    if ((u == Find(st) && v == Find(en)) || (u == Find(en) && v == Find(st))) {
      ans = w;
      break;
    }
    par[u] = v;
  }
  printf("%d", ans);
}