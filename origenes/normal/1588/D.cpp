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

int nxt[10][52][2][52], pos[10][52][2];

int id(char c) {
  if (isupper(c)) return c - 'A';
  return c - 'a' + 26;
}

void solve() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i, n) cin >> s[i];
  vector<vector<int>> f(52, vector<int>(1 << n, -1));
  vector<vector<pii>> pre(52, vector<pii>(1 << n, mp(-1, -1)));
  vector<vector<bool>> inq(52, vector<bool>(1 << n));
  reset(nxt, -1); reset(pos, -1);
  REP(i, n) {
    int len = s[i].length();
    REP(j, len) {
      int c = id(s[i][j]), se = pos[i][c][0] == -1 ? 0 : 1;
      pos[i][c][se] = j;
      REP(pc, 52) REP(pse, 2) if (pos[i][pc][pse] != -1 && (pc != c || pse != se)) {
        if (nxt[i][pc][pse][c] == -1) nxt[i][pc][pse][c] = se;
      }
    }
  }
  queue<pii> q;
  REP(c, 52) {
    bool bad = false;
    REP(i, n) if (pos[i][c][0] == -1) bad = true;
    if (!bad) {
      f[c][0] = 1;
      q.emplace(c, 0);
      inq[c][0] = true;
    }
  }
  while (!q.empty()) {
    auto [c, mask] = q.front(); q.pop();
    inq[c][mask] = false;
    REP(nc, 52) {
      bool bad = false;
      int nm = 0;
      REP(i, n) {
        int se = (mask >> i) & 1;
        if (nxt[i][c][se][nc] == -1) {
          bad = true;
          break;
        }
        if (nxt[i][c][se][nc]) nm |= 1 << i;
      }
      if (bad || f[c][mask] + 1 <= f[nc][nm]) continue;
      f[nc][nm] = f[c][mask] + 1;
      pre[nc][nm] = {c, mask};
      if (!inq[nc][nm]) {
        q.emplace(nc, nm);
        inq[nc][nm] = true;
      }
    }
  }
  int ec, em, ans = 0;
  REP(c, 52) REP(mask, 1 << n) if (f[c][mask] > ans) {
    ans = f[c][mask];
    ec = c;
    em = mask;
  }
  cout << ans << '\n';
  if (ans == 0) {
    cout << '\n';
    return;
  }
  stack<char> S;
  for (; ec != -1; tie(ec, em) = pre[ec][em]) {
    if (ec < 26) S.emplace(ec + 'A');
    else S.emplace(ec + 'a' - 26);
  }
  while (!S.empty()) {
    cout << S.top();
    S.pop();
  }
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}