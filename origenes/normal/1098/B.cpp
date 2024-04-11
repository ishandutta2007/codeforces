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

const char mat[] = "AGCT";

int n, m;

int go(vector<string> &lis, int n, int m, char ch1, char ch2, vector<string> &ret) {
  vector<char> mm[2];
  mm[0] = {ch1, ch2};
  REP(i, 4) if (mat[i] != mm[0][0] && mat[i] != mm[0][1]) mm[1].eb(mat[i]);
  int res = 0;
  REP(i, n) {
    int now[2] = {};
    REP(j, m) if (lis[i][j] != mm[i & 1][j & 1]) now[0]++;
    REP(j, m) if (lis[i][j] != mm[i & 1][j & 1 ^ 1]) now[1]++;
    if (now[0] < now[1]) {
      REP(j, m) ret[i][j] = mm[i & 1][j & 1];
      res += now[0];
    } else {
      REP(j, m) ret[i][j] = mm[i & 1][j & 1 ^ 1];
      res += now[1];
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  vector<string> lis(n);
  REP(i, n) cin >> lis[i];
  int res = n * m;
  vector<string> ans;
  bool rev = false;
  REP(i, 4) FOR(j, i + 1, 3) {
      vector<string> tmp(n, string(m, '\0'));
      int cur = go(lis, n, m, mat[i], mat[j], tmp);
      if (cur < res) {
        ans = tmp;
        res = cur;
      }
    }
  vector<string> lis2(m);
  REP(i, m) REP(j, n) lis2[i] += lis[j][i];
  REP(i, 4) FOR(j, i + 1, 3) {
      vector<string> tmp(m, string(n, '\0'));
      int cur = go(lis2, m, n, mat[i], mat[j], tmp);
      if (cur < res) {
        ans = tmp;
        rev = true;
        res = cur;
      }
    }
  if (rev) {
    REP(i, n) {
      REP(j, m) cout << ans[j][i];
      cout << '\n';
    }
  } else {
    REP(i, n) cout << ans[i] << '\n';
  }
}