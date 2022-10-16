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

ll debt[maxn];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    debt[u] += d;
    debt[v] -= d;
  }
  queue<int> q1, q2;
  FOR(i, 1, n) {
    if (debt[i] > 0) q1.emplace(i);
    else if (debt[i] < 0) q2.emplace(i);
  }
  vector<tuple<int, int, ll>> ans;
  while (!q1.empty()) {
    auto u = q1.front();
    assert(q2.size());
    auto v = q2.front();
    ll now = debt[u] + debt[v];
    if (now <= 0) {
      ans.eb(u, v, debt[u]);
      q1.pop();
      debt[v] = now;
      debt[u] = 0;
      if (now == 0) q2.pop();
    } else {
      ans.eb(u, v, -debt[v]);
      debt[u] = now;
      debt[v] = 0;
      q2.pop();
    }
  }
  printf("%d\n", int(ans.size()));
  for (auto x : ans) printf("%d %d %lld\n", get<0>(x), get<1>(x), get<2>(x));
}