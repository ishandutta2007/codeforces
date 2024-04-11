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

const int maxn = 512;

int dp[maxn][maxn], n;
string s;

int dfs(int l, int r) {
  if (l > r) return 0;
  if (dp[l][r] != -1) return dp[l][r];
  int &ret = dp[l][r];
  ret = 0;
  if (l == r) return ret = 1;
  ret = 1 + dfs(l + 1, r);
  FOR(i, l + 1, r) if (s[i] == s[l]) chkmin(ret, dfs(l + 1, i - 1) + dfs(i, r));
  return ret;
}

int main() {
  cin >> n >> s;
  uni(s);
  n = s.length();
  reset(dp, -1);
  cout << dfs(0, n - 1);
}