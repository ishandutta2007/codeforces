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

typedef pair<int, pii> Edge;

const int maxn = 212345;

int n, m, par[maxn], ans;
vector<Edge> vec;

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int u, int v) {
  int pu = Find(u), pv = Find(v);
  par[pu] = pv;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) par[i] = i;
  REP(i, m) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    vec.eb(w, mp(u, v));
  }
  sort(all(vec));
  int i = 0, j = 0;
  while (i < m) {
    vector<Edge> tmp;
    int cnt = 0;
    if (Find(vec[i]._2._1) != Find(vec[i]._2._2)) tmp.eb(vec[i]);
    for (j = i + 1; j < m; j++) {
      if (vec[j]._1 > vec[i]._1) break;
      if (Find(vec[j]._2._1) != Find(vec[j]._2._2)) tmp.eb(vec[j]);
    }
    i = j;
    for (const auto &it : tmp) if (Find(it._2._1) != Find(it._2._2))
        Union(it._2._1, it._2._2), cnt++;
    ans += int(tmp.size()) - cnt;
  }
  printf("%d", ans);
}