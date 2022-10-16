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

const int maxn = 213;

int a[maxn][maxn], tmp[maxn][maxn], row[maxn], col[maxn];
int n, m;

bool check(int r, int c) {
  FOR(i, 1, n) FOR(j, 1, m) tmp[i][j] = (i > r || (i == r && j >= c));
  row[1] = a[1][1] ^ tmp[1][1];
  FOR(i, 1, m) col[i] = a[1][i] ^ tmp[1][i] ^ row[1];
  FOR(i, 2, n) {
    row[i] = a[i][1] ^ tmp[i][1] ^ col[1];
    FOR(j, 2, m) if (tmp[i][j] != a[i][j] ^ row[i] ^ col[j]) return false;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) FOR(j, 1, m) scanf("%d", &a[i][j]);
  FOR(i, 1, n) FOR(j, 1, m) if (check(i, j)) {
    puts("YES");
    FOR(i, 1, n) printf("%d", row[i]);
    puts("");
    FOR(j, 1, m) printf("%d", col[j]);
    return 0;
  }
  puts("NO");
}