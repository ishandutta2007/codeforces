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

typedef pair<int, pii> Edge;

int n, m, k;
Edge e[maxn];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  FOR(i, 1, m) scanf("%d%d%d", &e[i]._2._1, &e[i]._2._2, &e[i]._1);
  sort(e + 1, e + 1 + m);
  set<int> ver;
  FOR(i, 1, k) {
    ver.emplace(e[i]._2._1);
    ver.emplace(e[i]._2._2);
  }
  map<int, int> id;
  for (auto u : ver) {
    int tmp = id.size();
    id[u] = tmp;
  }
  n = id.size();
  vector<vector<pii>> adj(n);
  FOR(i, 1, k) {
    int u = id[e[i]._2._1], v = id[e[i]._2._2];
    adj[u].eb(v, e[i]._1);
    adj[v].eb(u, e[i]._1);
  }
  vector<ll> lis;
  auto go = [&](int st) {
    vector<ll> dis(n, 1e18);
    dis[st] = 0;
    set<pair<ll, int>> q;
    q.emplace(0, st);
    while (!q.empty()) {
      auto now = *q.begin(); q.erase(q.begin());
      ll d = now._1;
      int u = now._2;
      if (dis[u] < d) continue;
      for (auto _ : adj[u]) {
        int w = _._2, v = _._1;
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          q.emplace(dis[v], v);
        }
      }
    }
    REP(i, n) if (i != st) lis.eb(dis[i]);
  };
  REP(i, n) go(i);
  nth_element(lis.begin(), lis.begin() + 2 * k - 2, lis.end());
  printf("%lld", lis[2 * k - 2]);
}