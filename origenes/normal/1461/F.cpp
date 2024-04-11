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
int a[maxn];
char ans[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  string s;
  cin >> s;
  if (s.length() == 1 || s == "+-" || s == "-+") {
    char c = s.length() == 1 ? s[0] : '+';
    FOR(i, 1, n - 1) cout << a[i] << c;
    cout << a[n];
    return 0;
  }
  if (s == "*-" || s == "-*") {
    bool f = false;
    FOR(i, 1, n - 1) {
      if (!f && a[i + 1] == 0) {
        ans[i] = '-';
        f = true;
      } else ans[i] = '*';
    }
    FOR(i, 1, n - 1) cout << a[i] << ans[i];
    cout << a[n];
    return 0;
  }
  int st = 1;
  auto work = [&](int en) {
    if (st > en) return;
    if (st == en) {
      ans[st - 1] = '+';
      return;
    }
    int cnt = 0, l = st, r = en;
    vector<int> pos;
    FOR(i, st, en) if (a[i] >= 2) {
      pos.eb(i);
      cnt++;
    }
    while (l <= en && a[l] == 1) {
      ans[l - 1] = '+';
      l++;
    }
    while (r >= st && a[r] == 1) {
      ans[r - 1] = '+';
      r--;
    }
    if (cnt == 0) return;
    if (cnt >= 20) {
      FOR(i, l, r - 1) ans[i] = '*';
      ans[l - 1] = '+';
      return;
    }
    vector<vector<ll>> mul(cnt, vector<ll>(cnt));
    REP(i, cnt) {
      mul[i][i] = a[pos[i]];
      FOR(j, i + 1, cnt - 1) mul[i][j] = mul[i][j - 1] * a[pos[j]];
    }
    vector<vector<ll>> f(cnt, vector<ll>(cnt));
    vector<vector<pii>> trace(cnt, vector<pii>(cnt,  mp(-1, -1)));
    f[0][0] = a[pos[0]];
    FOR(i, 1, cnt - 1) {
      f[i][0] = mul[0][i];
      FOR(j, 1, i) REP(k, j) if (f[i][j] < f[j - 1][k] + mul[j][i] + pos[j] - pos[j - 1] - 1) {
        f[i][j] = f[j - 1][k] + mul[j][i] + pos[j] - pos[j - 1] - 1;
        trace[i][j] = {j - 1, k};
      }
    }
    FOR(i, l, r) ans[i - 1] = '+';
    int x = cnt - 1, y = cnt - 1;
    REP(i, cnt - 1) if (f[x][i] > f[x][y]) y = i;
    while (x != -1) {
      FOR(i, pos[y], pos[x] - 1) ans[i] = '*';
      tie(x, y) = trace[x][y];
    }
  };
  FOR(i, 1, n) if (a[i] == 0) {
    work(i - 1);
    ans[i - 1] = '+';
    st = i + 1;
  }
  if (st <= n) work(n);
  FOR(i, 1, n - 1) cout << a[i] << ans[i];
  cout << a[n];
}