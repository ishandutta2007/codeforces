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

int f[maxn][1 << 4][2];
string s[2];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  REP(i, 2) {
    cin >> s[i];
    s[i] += "00";
  }
  reset(f, 0x3f);
  {
    int mask = 0;
    REP(i, 2) REP(j, 2) {
      int bit = 2 * i + j;
      if (s[j][i] == '1') mask |= 1 << bit;
    }
    f[0][mask][0] = 0;
  }
  REP(i, n) ROF(mask, (1 << 4) - 1, 0) REP(j, 2) if (f[i][mask][j] < 1e9) {
    int oj = 1 - j, skip = (mask >> oj) & 1, push = (mask >> 2 + j) & 1;
    if (skip == 0 && push == 0) {
      int nmask = (mask >> 2) + ((s[0][i + 2] == '1') << 2) + ((s[1][i + 2] == '1') << 3);
      chkmin(f[i + 1][nmask][j], f[i][mask][j]);
    } else if (skip == 1 && push == 1) {
      int nmask = mask ^ (1 << oj) ^ (1 << 2 + j);
      chkmin(f[i][nmask][oj], f[i][mask][j] + 1);
      nmask = (nmask >> 2) + ((s[0][i + 2] == '1') << 2) + ((s[1][i + 2] == '1') << 3);
      chkmin(f[i + 1][nmask][j], f[i][mask][j] + 1);
    } else if (skip == 1) {
      int nmask = mask ^ (1 << oj);
      chkmin(f[i][nmask][oj], f[i][mask][j]);
      chkmin(f[i][nmask][j], f[i][mask][j] + 1);
    } else {
      int nmask = mask ^ (1 << 2 + j);
      nmask = (nmask >> 2) + ((s[0][i + 2] == '1') << 2) + ((s[1][i + 2] == '1') << 3);
      chkmin(f[i + 1][nmask][j], f[i][mask][j]);
    }
  }
  cout << count(all(s[0]), '1') + count(all(s[1]), '1') - min(f[n][0][0], f[n][0][1]) << '\n';
}