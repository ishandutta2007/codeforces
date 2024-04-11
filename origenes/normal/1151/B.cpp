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

int a[maxn][maxn], n, m;

int main() {
  scanf("%d%d", &n, &m);
  pii rec = {-1, -1};
  FOR(i, 1, n) {
    FOR(j, 1, m) scanf("%d", &a[i][j]);
    if (rec._1 == -1) {
      FOR(j, 2, m) if (a[i][j] != a[i][1]) {
        rec = {i, j};
        break;
      }
    }
  }
  if (rec._1 == -1) {
    int s = 0;
    FOR(i, 1, n) s ^= a[i][1];
    if (s) {
      puts("TAK");
      FOR(i, 1, n) printf("%d ", 1);
    } else puts("NIE");
  } else {
    puts("TAK");
    int s = 0;
    FOR(i, 1, n) s ^= a[i][1];
    if (s) {
      FOR(i, 1, n) printf("%d ", 1);
    } else {
      FOR(i, 1, n) {
        if (i == rec._1) printf("%d ", rec._2);
        else printf("%d ", 1);
      }
    }
  }
}