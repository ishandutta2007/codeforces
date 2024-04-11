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

const int maxn = 112345678;

bool vis[maxn];
int n, d, e, ans;

int main() {
  cin >> n >> d >> e;
  ans = n;
  vis[n] = true;
  queue<int> q;
  q.emplace(n);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    chkmin(ans, u);
    if (u >= d && !vis[u - d]) {
      vis[u - d] = true;
      q.emplace(u - d);
    }
    if (u >= 5 * e && !vis[u - 5 * e]) {
      vis[u - 5 * e] = true;
      q.emplace(u - 5 * e);
    }
  }
  printf("%d", ans);
}