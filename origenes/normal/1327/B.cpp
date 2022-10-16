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

vector<int> g[maxn];
int n;
bool vis[maxn];

void solve() {
  scanf("%d", &n);
  fill(vis + 1, vis + n + 1, false);
  FOR(i, 1, n) {
    int k;
    scanf("%d", &k);
    g[i] = vector<int>(k);
    for (auto &x : g[i]) scanf("%d", &x);
  }
  int fi = -1;
  FOR(i, 1, n) {
    bool matched = false;
    for (auto j : g[i]) if (!vis[j]) {
      vis[j] = true;
      matched = true;
      break;
    }
    if (!matched && fi == -1) fi = i;
  }
  if (fi == -1) puts("OPTIMAL");
  else {
    puts("IMPROVE");
    int se;
    FOR(i, 1, n) if (!vis[i]) {
      se = i;
      break;
    }
    printf("%d %d\n", fi, se);
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}