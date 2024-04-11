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

const int maxn = 112345;
const int MOD = 1e9 + 7;

int pw[maxn], deg[maxn];
int n, lv;

inline int add(int a, int b) {
  a += b;
  return a >= MOD ? a - MOD : a;
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    deg[u]++, deg[v]++;
  }
  FOR(i, 1, n) lv += (deg[i] == 1);
  pw[0] = 1;
  FOR(i, 1, n) pw[i] = add(pw[i - 1], pw[i - 1]);
  int ans = 0;
  FOR(i, 1, n) ans = add(ans, pw[n - lv + (deg[i] == 1)]);
  printf("%d", ans);
}