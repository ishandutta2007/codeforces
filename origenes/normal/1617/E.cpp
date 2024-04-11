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

int ans, id1, id2;
int a[maxn], id[maxn * 30];
vector<int> G[maxn * 30];

pii dfs(int u, int par) {
  pii d[2];
  d[0] = d[1] = mp(-1, -1);
  if (id[u]) d[0] = {0, id[u]};
  for (auto v : G[u]) if (v != par) {
    auto cur = dfs(v, u);
    if (cur._1 == -1) continue;
    cur._1++;
    if (cur._1 > d[0]._1) {
      swap(d[0], d[1]);
      d[0] = cur;
    } else if (cur._1 > d[1]._1) d[1] = cur;
  }
  if (d[1]._1 != -1) {
    if (d[0]._1 + d[1]._1 > ans) {
      ans = d[0]._1 + d[1]._1;
      id1 = d[0]._2; id2 = d[1]._2;
    }
  }
  return d[0];
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  FOR(i, 1, n) cin >> a[i];
  map<int, int> to;
  FOR(i, 1, n) {
    if (!to.count(a[i])) {
      int tot = to.size();
      to[a[i]] = ++tot;
    }
    int pre = to[a[i]];
    id[pre] = i;
    int now = a[i], k = 29;
    do {
      while (k >= 0 && (1 << k) >= now) k--;
      k++;
      now = (1 << k) - now;
      if (!to.count(now)) {
        int tot = to.size();
        to[now] = ++tot;
      }
      int cur = to[now];
      G[cur].eb(pre); G[pre].eb(cur);
      pre = cur;
    } while (now != 0);
  }
  int root = to[0], tot = to.size();
  FOR(i, 1, tot) {
    sort(all(G[i]));
    uni(G[i]);
  }
  dfs(root, 0);
  cout << id1 << ' ' << id2 << ' ' << ans << '\n';
}