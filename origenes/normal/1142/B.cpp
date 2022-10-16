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

const int maxn = 212345;

int n, m, q;
int p[maxn], a[maxn], id[maxn], st[2][maxn][19], pre[maxn];
vector<int> G[maxn];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  FOR(i, 1, n) {
    scanf("%d", p + i);
    id[p[i]] = i;
  }
  FOR(i, 1, m) {
    scanf("%d", a + i);
    a[i] = id[a[i]];
    int need = a[i] - 1;
    if (!need) need = n;
    st[0][i][0] = pre[need];
    pre[a[i]] = i;
  }
  FOR(j, 1, 18) FOR(i, 1, m) st[0][i][j] = st[0][st[0][i][j - 1]][j - 1];
  FOR(i, 1, m) {
    int rem = n - 1, now = i;
    ROF(j, 18, 0) if (rem >= 1 << j) {
      rem -= 1 << j;
      now = st[0][now][j];
    }
    st[1][i][0] = now;
  }
  FOR(i, 1, 18) FOR(j, 1, m + 1 - (1 << i))
    st[1][j][i] = max(st[1][j + (1 << i - 1)][i - 1], st[1][j][i - 1]);
  while (q--) {
    int lo, hi;
    scanf("%d%d", &lo, &hi);
    int val = floor(log(hi - lo + 1) / log(2));
    putchar(max(st[1][lo][val], st[1][hi - (1 << val) + 1][val]) >= lo ? '1' : '0');
  }
}