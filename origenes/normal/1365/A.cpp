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

const int maxn = 55;

int a[maxn][maxn];
int n, m;
bool vc[maxn], vr[maxn];

void solve() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) FOR(j, 1, m) scanf("%d", &a[i][j]);
  reset(vc, 0); reset(vr, 0);
  FOR(i, 1, n) FOR(j, 1, m) if (a[i][j]) vr[i] = vc[j] = true;
  int c = 0, r = 0;
  FOR(i, 1, n) if (!vr[i]) r++;
  FOR(j, 1, m) if (!vc[j]) c++;
  puts(min(c, r) & 1 ? "Ashish" : "Vivek");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}