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

const int maxn = 512;

int n, tot;
int a[maxn][maxn], c[maxn * 2], id[maxn];
vector<pii> edges;

int solve(int l, int r) {
  if (l == r) {
    c[id[l]] = a[id[l]][id[l]];
    return id[l];
  }
  int mx = 0;
  FOR(i, l, r) chkmax(mx, a[id[l]][id[i]]);
  int u = ++tot;
  c[u] = mx;
  for (int i = l; i <= r; ) {
    int k = r;
    for (int j = i + 1; j <= k; ) {
      if (a[id[i]][id[j]] == mx) {
        swap(id[j], id[k]);
        k--;
      } else j++;
    }
    int v = solve(i, k);
    edges.eb(v, u);
    i = k + 1;
  }
  return u;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];
  iota(id + 1, id + n + 1, 1);
  tot = n;
  int r = solve(1, n);
  cout << tot << '\n';
  FOR(i, 1, tot) cout << c[i] << ' ';
  cout << '\n';
  cout << r << '\n';
  for (auto [u, v] : edges) cout << u << ' ' << v << '\n';
}