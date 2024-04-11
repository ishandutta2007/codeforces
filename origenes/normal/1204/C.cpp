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

const int maxn = 112;
const int maxm = 1123456;

char G[maxn][maxn];
int n, m;
int dis[maxn][maxn], p[maxm];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%s", G[i] + 1);
  reset(dis, 0x3f);
  FOR(i, 1, n) FOR(j, 1, n) {
    if (j == i) dis[i][j] = 0;
    else if (G[i][j] == '1') dis[i][j] = 1;
  }
  FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) chkmin(dis[i][j], dis[i][k] + dis[k][j]);
  scanf("%d", &m);
  FOR(i, 1, m) scanf("%d", p + i);
  int j = 1;
  vector<int> ans = {p[1]};
  FOR(i, 2, m) if (dis[p[j]][p[i]] != i - j) {
    ans.eb(p[i - 1]);
    j = i - 1;
  }
  ans.eb(p[m]);
  printf("%d\n", int(ans.size()));
  for (auto it : ans) printf("%d ", it);
}