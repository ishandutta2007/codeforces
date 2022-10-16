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

const int maxn = 112345;

int n, good;
int val[maxn], l[maxn], r[maxn], deg[maxn];
map<int, int> cnt;

void dfs(int u, int lo, int hi) {
  if (lo > hi) return;
  if (lo <= val[u] && val[u] <= hi) good += cnt[val[u]];
  if (l[u] != -1) dfs(l[u], lo, min(val[u] - 1, hi));
  if (r[u] != -1) dfs(r[u], max(val[u] + 1, lo), hi);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d%d%d", val + i, l + i, r + i);
    cnt[val[i]]++;
    if (l[i] != -1) deg[l[i]]++;
    if (r[i] != -1) deg[r[i]]++;
  }
  FOR(i, 1, n) if (!deg[i]) {
    dfs(i, 0, 1e9 + 10);
    break;
  }
  printf("%d", n - good);
}