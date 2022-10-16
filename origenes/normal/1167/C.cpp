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

const int maxn = 512345;

int par[maxn], cnt[maxn];
int n, m;

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int x, int y) {
  x = Find(x), y = Find(y);
  if (x == y) return;
  par[y] = x;
  cnt[x] += cnt[y];
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) par[i] = i, cnt[i] = 1;
  while (m--) {
    int k, u, v;
    scanf("%d", &k);
    if (!k) continue;
    scanf("%d", &u);
    FOR(i, 2, k) {
      scanf("%d", &v);
      Union(u, v);
    }
  }
  FOR(i, 1, n) printf("%d ", cnt[Find(i)]);
}