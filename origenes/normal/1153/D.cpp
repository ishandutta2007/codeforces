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

const int maxn = 312345;

int dp[maxn], tab[maxn], n;
vector<int> ch[maxn];

int dfs(int u) {
  if (tab[u]) {
    dp[u] = n + 5;
    for (int v : ch[u]) chkmin(dp[u], dfs(v));
  } else {
    dp[u] = 0;
    for (int v : ch[u]) dp[u] += dfs(v);
  }
  if (ch[u].empty()) dp[u] = 1;
  return dp[u];
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", tab + i);
  FOR(i, 2, n) {
    int f;
    scanf("%d", &f);
    ch[f].eb(i);
  }
  int leaf = 0;
  FOR(i, 1, n) if (ch[i].empty()) leaf++;
  printf("%d", leaf - dfs(1) + 1);
}