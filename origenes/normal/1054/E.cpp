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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 312;

int n, m;
string st[maxn][maxn], en[maxn][maxn];

void solve(string mat[maxn][maxn], vector<pair<pii, pii>> &ans) {
  queue<char> o;
  ROF(k, int(mat[1][1].size()) - 1, 0) o.emplace(mat[1][1][k]);
  FOR(i, 2, n) ROF(k, int(mat[i][1].size()) - 1, 0) {
    o.emplace(mat[i][1][k]);
    ans.eb(mp(i, 1), mp(1, 1));
  }
  FOR(j, 2, m) ROF(k, int(mat[1][j].size()) - 1, 0) {
    o.emplace(mat[1][j][k]);
    ans.eb(mp(1, j), mp(1, 1));
  }
  vector<int> row(m + 1), col(n + 1);
  FOR(i, 2, n) FOR(j, 2, m) ROF(k, int(mat[i][j].size()) - 1, 0) {
    auto now = mat[i][j][k];
    if (now == '0') {
      row[j]++;
      ans.eb(mp(i, j), mp(1, j));
    } else {
      col[i]++;
      ans.eb(mp(i, j), mp(i, 1));
    }
  }
  while (!o.empty()) {
    auto now = o.front(); o.pop();
    if (now == '0') ans.eb(mp(1, 1), mp(1, 2));
    else ans.eb(mp(1, 1), mp(2, 1));
  }
  FOR(i, 3, n) while (col[i]--) ans.eb(mp(i, 1), mp(2, 1));
  FOR(j, 3, m) while (row[j]--) ans.eb(mp(1, j), mp(1, 2));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  FOR(i, 1, n) FOR(j, 1, m) cin >> st[i][j];
  FOR(i, 1, n) FOR(j, 1, m) {
    cin >> en[i][j];
    reverse(all(en[i][j]));
  }
  vector<pair<pii, pii>> ans1, ans2;
  solve(st, ans1);
  solve(en, ans2);
  cout << ans1.size() + ans2.size() << '\n';
  for (auto it : ans1) cout << it._1._1 << ' ' << it._1._2 << ' ' << it._2._1 << ' ' << it._2._2 << '\n';
  reverse(all(ans2));
  for (auto it : ans2) cout << it._2._1 << ' ' << it._2._2 << ' ' << it._1._1 << ' ' << it._1._2 << '\n';
}