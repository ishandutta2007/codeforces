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

const int maxn = 212;

int n;
double w[maxn][maxn], a[maxn][maxn], b[maxn][maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) FOR(j, 1, n) scanf("%lf", &w[i][j]);
  FOR(i, 1, n) FOR(j, i + 1, n) {
    a[i][j] = (w[i][j] + w[j][i]) / 2;
    b[i][j] = (w[i][j] - w[j][i]) / 2;
    a[j][i] = a[i][j], b[j][i] = -b[i][j];
  }
  FOR(i, 1, n) a[i][i] = w[i][i];
  FOR(i, 1, n) {
    FOR(j, 1, n) printf("%.10lf ", a[i][j]);
    putchar('\n');
  }
  FOR(i, 1, n) {
    FOR(j, 1, n) printf("%.10lf ", b[i][j]);
    putchar('\n');
  }
}