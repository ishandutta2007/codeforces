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

int n;
int f[1 << 20];
string s[20];
int pre[20], v[20], suf[20];
int en[20][412345];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  int ans = 0;
  REP(i, n) {
    cin >> s[i];
    int m = s[i].length();
    vector<int> g(m);
    g[0] = s[i][0] == '(' ? 1 : -1;
    FOR(j, 1, m - 1) {
      g[j] = g[j - 1];
      if (s[i][j] == '(') g[j]++;
      else g[j]--;
    }
    int p = 0;
    REP(j, m) if (g[j] < 0 && g[j] < g[p]) p = j;
    if (g[p] < 0) {
      pre[i] = -g[p];
      int cnt = 0, balance = 0;
      REP(j, p) {
        if (s[i][j] == '(') cnt++;
        else {
          if (cnt > 0) {
            if (--cnt == 0) en[i][-balance]++;
          } else balance--;
        }
      }
    } else p--;
    int cnt = 0, now = 0;
    FOR(j, p + 1, m - 1) {
      if (s[i][j] == '(') cnt++;
      else {
        cnt--;
        if (cnt == 0) now++;
      }
    }
    v[i] = now;
    suf[i] = cnt;
  }
  reset(f, 0xc0);
  f[0] = 0;
  REP(mask, 1 << n) {
    int prefix = 0;
    REP(i, n) if (mask & (1 << i)) prefix += suf[i] - pre[i];
    if (prefix < 0) continue;
    chkmax(ans, f[mask]);
    REP(i, n) if ((mask & (1 << i)) == 0) {
      if (prefix < pre[i]) {
        chkmax(ans, f[mask] + en[i][prefix] + (prefix > 0));
        continue;
      }
      if (prefix == pre[i]) chkmax(f[mask | (1 << i)], f[mask] + v[i] + (prefix > 0));
      else chkmax(f[mask | (1 << i)], f[mask]);
    }
  }
  cout << ans;
}