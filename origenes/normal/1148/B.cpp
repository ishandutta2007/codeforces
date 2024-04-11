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

int a[maxn], b[maxn], nxt[maxn];
int n, m, ta, tb, k, ans;

int main() {
  scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, m) scanf("%d", b + i);
  if (k >= n) {
    puts("-1");
    return 0;
  }
  int j = 1;
  FOR(i, 1, k + 1) {
    int now = ta + a[i];
    while (b[j] < now) j++;
    nxt[i] = j + k - i + 1;
  }
  FOR(i, 1, k + 1) if (nxt[i] > m) {
    puts("-1");
    return 0;
  }
  FOR(i, 1, k + 1) chkmax(ans, b[nxt[i]] + tb);
  printf("%d", ans);
}