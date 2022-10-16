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

const int maxn = 5123;

int n, m;
char s[maxn][maxn];
int tab[maxn][maxn];
int id[maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%s", s[i] + 1);
  FOR(i, 1, n) ROF(j, m, 1) if (s[i][j] == '1') tab[j][i] = tab[j + 1][i] + 1;
  iota(id + 1, id + n + 1, 1);
  int ans = 0;
  FOR(j, 1, m) {
    sort(id + 1, id + n + 1, [&](int a, int b) { return tab[j][a] > tab[j][b]; });
    FOR(i, 1, n) chkmax(ans, tab[j][id[i]] * i);
  }
  printf("%d", ans);
}