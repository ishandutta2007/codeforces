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

const int maxn = 1123;

int n, d;
int par[maxn], sz[maxn];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int x, int y) {
  x = Find(x), y = Find(y);
  if (x != y) {
    par[x] = y;
    sz[y] += sz[x];
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> d;
  iota(par + 1, par + n + 1, 1);
  FOR(i, 1, n) sz[i] = 1;
  int cnt = 0;
  while (d--) {
    int x, y;
    cin >> x >> y;
    x = Find(x), y = Find(y);
    if (x == y) cnt++;
    else Union(x, y);
    vector<int> comps;
    FOR(i, 1, n) comps.eb(Find(i));
    sort(all(comps));
    uni(comps);
    for (auto &id : comps) id = sz[id];
    sort(all(comps), greater<>());
    int ans = comps[0] - 1;
    FOR(i, 1, cnt) ans += comps[i];
    cout << ans << '\n';
  }
}