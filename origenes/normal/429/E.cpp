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

int n;
int c[maxn];
pii seg[maxn];
vector<int> G[maxn];

void dfs(int u, int x) {
  if (c[u] != -1) return;
  c[u] = x;
  for (auto v : G[u]) dfs(v, 1 - x);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n) {
    int l, r; cin >> l >> r;
    G[2 * i].eb(2 * i + 1);
    G[2 * i + 1].eb(2 * i);
    seg[2 * i] = {l, 2 * i};
    seg[2 * i + 1] = {r + 1, 2 * i + 1};
  }
  sort(seg, seg + 2 * n);
  REP(i, n) {
    G[seg[2 * i]._2].eb(seg[2 * i + 1]._2);
    G[seg[2 * i + 1]._2].eb(seg[2 * i]._2);
  }
  reset(c, -1);
  REP(i, 2 * n) if (c[i] == -1) dfs(i, 0);
  REP(i, n) cout << c[i * 2] << ' ';
}