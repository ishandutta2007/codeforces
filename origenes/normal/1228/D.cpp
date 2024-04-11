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

const int maxn = 1e5 + 5;

vector<int> G[maxn];
bitset<maxn> now, mask[5];
int n, m, lab[maxn], cnt;

int main() {
  scanf("%d%d", &n, &m);
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  FOR(i, 1, n) if (!lab[i] && cnt < 3) {
    lab[i] = ++cnt;
#undef reset
    now.reset();
    for (auto x : G[i]) now.set(x);
    FOR(j, i + 1, n) if (!lab[j] && !now[j]) lab[j] = cnt;
  }
  if (cnt < 3) {
    puts("-1");
    return 0;
  }
  FOR(i, 1, n) if (!lab[i]) {
    puts("-1");
    return 0;
  }
  FOR(i, 1, n) mask[lab[i]].set(i);
  FOR(i, 1, n) {
    now.reset();
    for (auto x : G[i]) now.set(x);
    if ((now & mask[lab[i]]).count() || (now | mask[lab[i]]).count() != n) {
      puts("-1");
      return 0;
    }
  }
  FOR(i, 1, n) printf("%d ", lab[i]);
}