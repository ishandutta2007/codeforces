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

const int MOD = 1e9 + 7;
const int i100 = 570000004;

int n, prob[7][7];
int tab[1 << 7];
vector<int> mask[8];

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int main() {
  REP(i, 7) prob[i][i] = 1;
  scanf("%d", &n);
  REP(i, n) REP(j, n) {
    int p; scanf("%d", &p);
    prob[i][j] = mul(p, i100);
  }
  REP(i, 1 << 7) {
    int now = __builtin_popcount(i);
    tab[i] = mask[now].size();
    mask[now].eb(i);
  }
  map<ll, int> f;
  f[1] = 1;
  REP(i, 7) {
    map<ll, int> g;
    for (auto x : f) {
      vector<ll> nmask(7);
      int sz = mask[i].size();
      REP(j, sz) if ((x._1 >> j) & 1) {
        auto cur = mask[i][j];
        REP(k, 7) if (!(cur & (1 << k))) nmask[k] |= 1LL << tab[cur ^ (1 << k)];
      }
      REP(j, 1 << 7) {
        int p = 1;
        ll tot = 0;
        REP(k, 7) {
          if (j & (1 << k)) p = mul(p, prob[i][k]), tot |= nmask[k];
          else p = mul(p, add(1, MOD - prob[i][k]));
        }
        g[tot] = add(g[tot], mul(p, x._2));
      }
    }
    f = g;
  }
  printf("%d", f[1]);
}