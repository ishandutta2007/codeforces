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

int n, cnt[maxn], ans;
char y[maxn];
int vis[maxn];

bool dfs(int u, int off, int c) {
  vis[u] = c;
  int v = (u + off) % n;
  if (y[u]) {
    if (vis[v] == c) return false;
    if (!vis[v] && !dfs(v, off, 3 - c)) return false;
    return true;
  }
  if (vis[v] == 3 - c) return false;
  if (!vis[v] && !dfs(v, off, c)) return false;
  return true;
}

bool check(int off) {
  fill(vis, vis + n, 0);
  REP(i, n) if (!vis[i] && !dfs(i, off, 1)) return false;
  return true;
}

int main() {
  scanf("%d", &n);
  scanf("%s", y);
  REP(i, n) y[i] -= '0';
  FOR(i, 1, n) cnt[__gcd(i, n)]++;
  FOR(i, 1, n) if (__gcd(i, n) == i && check(i)) ans += cnt[i];
  printf("%d", ans);
}