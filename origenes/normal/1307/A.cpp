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

const int maxn = 112;

int a[maxn];
int n, d;

void solve() {
  scanf("%d%d", &n, &d);
  FOR(i, 1, n) scanf("%d", a + i);
  int ans = a[1];
  FOR(i, 2, n) {
    int need = i - 1;
    while (a[i] && d >= need) ans++, d -= need, a[i]--;
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}