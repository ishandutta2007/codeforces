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

const int maxn = 412345;

inline int lowbit(int x) {
  return x & -x;
}

int n;
int a[maxn], pre[maxn][20];
ll s[20][1 << 20], f[1 << 20];
vector<int> G[20];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    a[i]--;
    G[a[i]].eb(i);
  }
  FOR(i, 1, n) {
    memcpy(pre[i], pre[i - 1], sizeof(pre[i]));
    pre[i][a[i]]++;
  }
  REP(i, 20) REP(j, int(G[i].size())) {
    int idx = G[i][j];
    REP(k, 20) s[i][1 << k] += pre[idx][k];
  }
  REP(i, 20) REP(mask, 1 << 20) s[i][mask] = s[i][mask ^ lowbit(mask)] + s[i][lowbit(mask)];
  reset(f, 0x3f);
  f[0] = 0;
  FOR(mask, 1, (1 << 20) - 1) REP(i, 20) if (mask & (1 << i)) chkmin(f[mask], f[mask ^ (1 << i)] + s[i][(1 << 20) - 1] - s[i][mask]);
  printf("%lld", f[(1 << 20) - 1]);
}