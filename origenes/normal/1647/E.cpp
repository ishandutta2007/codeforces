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

int n;
int p[maxn], a[maxn], deg[maxn], to[maxn][30], nex[maxn], b[maxn];
bool used[maxn], done[maxn];

int Find(int x) {
  if (!used[x]) return x;
  return nex[x] = Find(nex[x]);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> p[i];
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) {
    deg[p[i]]++;
    to[i][0] = p[i];
    nex[i] = i + 1;
  }
  int roots = 0, mx = 0;
  FOR(i, 1, n) if (!deg[i]) roots++;
  FOR(i, 1, n) {
    chkmax(mx, a[i]);
    if (a[i] <= n) used[a[i]] = true;
  }
  int rounds = (mx - n) / roots;
  FOR(j, 1, 29) FOR(i, 1, n) to[i][j] = to[to[i][j - 1]][j - 1];
  FOR(i, 1, n) {
    int need = rounds, u = i;
    ROF(j, 29, 0) if (need >= 1 << j) {
      need -= 1 << j;
      u = to[u][j];
    }
    if (!done[u]) {
      b[i] = a[u];
      done[u] = true;
    } else {
      b[i] = Find(a[u]);
      used[b[i]] = true;
    }
  }
  FOR(i, 1, n) cout << b[i] << ' ';
}