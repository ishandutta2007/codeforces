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

const int maxn = 212345;

int last[maxn], a[maxn], suf[maxn];
int n, q;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  scanf("%d", &q);
  FOR(i, 1, q) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int p, x;
      scanf("%d%d", &p, &x);
      last[p] = i;
      a[p] = x;
    } else {
      int x;
      scanf("%d", &x);
      suf[i] = x;
    }
  }
  ROF(i, q, 1) chkmax(suf[i], suf[i + 1]);
  FOR(i, 1, n) printf("%d ", max(a[i], suf[last[i] + 1]));
}