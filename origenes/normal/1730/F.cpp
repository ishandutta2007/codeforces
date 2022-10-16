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

const int maxn = 5123;

int n, k;
int p[maxn], pos[maxn], f[maxn][1 << 9], pre[maxn][maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  FOR(i, 1, n) {
    cin >> p[i];
    pos[p[i]] = i;
  }
  FOR(i, 1, n) FOR(j, i + 1, n) pre[i][j] = pre[i - 1][j] + (pos[i] > pos[j]);
  reset(f, 0x3f);
  f[1][0] = 0;
  FOR(st, 1, n) REP(mask, 1 << min(n - st, k)) {
    int ni = st + 1, b = 0;
    while (mask >> b & 1) ni++, b++;
    chkmin(f[ni][mask >> b + 1], f[st][mask] + pre[st - 1][st]);
    FOR(i, 1, min(k, n - st)) {
      int pp = st + i, d = pre[st - 1][pp];
      FOR(j, 1, i - 1) if (mask >> (j - 1) & 1) d += pos[st + j] > pos[pp];
      chkmin(f[st][mask | (1 << i - 1)], f[st][mask] + d);
    }
  }
  cout << f[n + 1][0];
}