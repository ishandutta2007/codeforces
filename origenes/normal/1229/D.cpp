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

bitset<120> mask[156];
int sz[156], G[156][120], comb[120][120];
vector<int> perm[120];

void init() {
  {
    vector<int> a(5);
    iota(all(a), 0);
    int now = 0;
    do {
      perm[now++] = a;
    } while (next_permutation(all(a)));
  }
  {
    REP(i, 120) REP(j, 120) {
      vector<int> a(5);
      REP(k, 5) a[k] = perm[i][perm[j][k]];
      comb[i][j] = lower_bound(perm, perm + 120, a) - perm;
    }
  }
  {
    bitset<120> bs;
    bs.set(0);
    int tot = 0;
    mask[tot++] = bs;
    REP(i, tot) {
      sz[i] = mask[i].count();
      REP(u, 120) {
        bitset<120> nmask = mask[i];
        nmask.set(u);
        vector<int> q;
        for (int v = nmask._Find_first(); v < 120; v = nmask._Find_next(v)) q.eb(v);
        REP(x, int(q.size())) REP(y, x + 1) {
          int v = comb[q[x]][q[y]];
          if (!nmask[v]) {
            nmask.set(v);
            q.eb(v);
          }
          v = comb[q[y]][q[x]];
          if (!nmask[v]) {
            nmask.set(v);
            q.eb(v);
          }
        }
        int j = 0;
        while (j < tot && mask[j] != nmask) j++;
        if (j == tot) {
          mask[j] = nmask;
          tot++;
        }
        G[i][u] = j;
      }
    }
  }
}

int n, k;
int cnt1[156], cnt2[156];
ll ans;

int main() {
  init();
  scanf("%d%d", &n, &k);
  while (n--) {
    vector<int> p(5);
    iota(all(p), 0);
    REP(i, k) {
      scanf("%d", &p[i]);
      p[i]--;
    }
    int i = lower_bound(perm, perm + 120, p) - perm;
    cnt1[0]++;
    reset(cnt2, 0);
    REP(j, 156) cnt2[G[j][i]] += cnt1[j];
    REP(j, 156) {
      cnt1[j] = cnt2[j];
      ans += ll(cnt1[j]) * sz[j];
    }
  }
  printf("%lld", ans);
}