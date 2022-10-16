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
queue<pii> rec[maxn];
int id[maxn];
bool vis[maxn], bad[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, m) {
    string op; int x;
    cin >> op >> x;
    vis[x] = true;
    id[i] = x;
    if (op == "+") rec[x].emplace(i, 1);
    else rec[x].emplace(i, -1);
  }
  vector<int> ans;
  int cnt = 0;
  FOR(i, 1, n) {
    if (!vis[i]) ans.eb(i);
    else if (rec[i].front()._2 == -1) cnt++;
  }
  if (cnt) FOR(i, 1, n) if (vis[i] && rec[i].front()._2 == 1) bad[i] = true;
  set<int> only;
  FOR(i, 1, m) {
    int x = id[i];
    auto [_, op] = rec[x].front(); rec[x].pop();
    if (op == 1) {
      if (!cnt) only.emplace(x);
      else bad[x] = true;
      cnt++;
    } else if (--cnt) bad[x] = true;
  }
  if (only.empty()) FOR(i, 1, n) if (vis[i] && !bad[i]) ans.eb(i);
  if (only.size() == 1 && !bad[*only.begin()]) ans.eb(*only.begin());
  cout << ans.size() << '\n';
  sort(all(ans));
  for (auto x : ans) cout << x << ' ';
}