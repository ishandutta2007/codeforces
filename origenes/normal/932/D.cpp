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

const int maxn = 412345;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int anc[maxn][19], w[maxn], cnt = 1, Q;
ll x[maxn][19];

int main() {
  ll last = 0;
  scanf("%d", &Q);
  reset(x[1], 0x3f);
  w[0] = 2e9;
  while (Q--) {
    int op;
    ll p, q;
    scanf("%d%lld%lld", &op, &p, &q);
    if (op == 1) {
      int R = p ^ last, W = q ^ last;
      w[++cnt] = W;
      if (w[cnt] <= w[R]) {
        anc[cnt][0] = R;
      } else {
        int now = R;
        ROF(i, 18, 0) if (w[anc[now][i]] < w[cnt]) now = anc[now][i];
        anc[cnt][0] = anc[now][0];
      }
      if (anc[cnt][0]) x[cnt][0] = w[anc[cnt][0]];
      else x[cnt][0] = inf;
      FOR(i, 1, 18) {
        anc[cnt][i] = anc[anc[cnt][i - 1]][i - 1];
        if (anc[cnt][i]) x[cnt][i] = x[cnt][i - 1] + x[anc[cnt][i - 1]][i - 1];
        else x[cnt][i] = inf;
      }
    } else {
      int R = p ^ last;
      ll X = q ^ last;
      if (w[R] > X) {
        puts("0");
        last = 0;
        continue;
      }
      X -= w[R];
      int ans = 1;
      ROF(i, 18, 0) if (x[R][i] <= X) {
          ans += 1 << i;
          X -= x[R][i];
          R = anc[R][i];
        }
      printf("%d\n", ans);
      last = ans;
    }
  }
}