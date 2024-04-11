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

const int maxn = 512;

int n, m;
int a[maxn][maxn], b[maxn][maxn];
vector<int> lis[maxn * 2][2];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) FOR(j, 1, m) {
    scanf("%d", &a[i][j]);
    lis[i + j][0].eb(a[i][j]);
  }
  FOR(i, 1, n) FOR(j, 1, m) {
    scanf("%d", &b[i][j]);
    lis[i + j][1].eb(b[i][j]);
  }
  FOR(i, 2, n + m) {
    REP(j, 2) sort(all(lis[i][j]));
    if (lis[i][0] != lis[i][1]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
}