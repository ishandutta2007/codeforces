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

int n, k;
int nx[sqr(maxn)], ny[sqr(maxn)], mx[sqr(maxn)], my[sqr(maxn)], s[maxn][maxn];
bool occ[sqr(maxn)];

void update(int x1, int x2, int y1, int y2, int l) {
  chkmax(x1, 1); chkmax(y1, 1);
  chkmin(x2, n - l); chkmin(y2, n - l);
  if (x1 <= x2 && y1 <= y2) {
    s[x1][y1]++;
    s[x1][y2 + 1]--; s[x2 + 1][y1]--;
    s[x2 + 1][y2 + 1]++;
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  FOR(i, 1, sqr(n)) nx[i] = ny[i] = sqr(maxn);
  FOR(i, 1, n) FOR(j, 1, n) {
    int v; cin >> v;
    occ[v] = true;
    chkmin(nx[v], i); chkmax(mx[v], i);
    chkmin(ny[v], j); chkmax(my[v], j);
  }
  int cnt = 0;
  FOR(i, 1, sqr(n)) cnt += occ[i];
  if (cnt <= k) {
    cout << k - cnt;
    return 0;
  }
  REP(l, n) {
    FOR(i, 1, sqr(n)) if (nx[i] != sqr(maxn)) update(mx[i] - l, nx[i], my[i] - l, ny[i], l);
    FOR(i, 1, n) FOR(j, 1, n) {
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
      if (cnt - s[i][j] == k || cnt - s[i][j] == k - 1) {
        cout << 1;
        return 0;
      }
    }
    reset(s, 0);
  }
  cout << 2;
}