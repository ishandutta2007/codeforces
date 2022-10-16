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

const int maxn = 512;

int ans[maxn][maxn];
int r, c;

int main() {
  scanf("%d%d", &r, &c);
  bool f = false;
  if (r > c) {
    swap(r, c);
    f = true;
  }
  FOR(i, 1, r) FOR(j, 1, c) ans[i][j] = i * (r + j);
  set<int> s;
  FOR(i, 1, r) {
    int d = 0;
    FOR(j, 1, c) d = __gcd(d, ans[i][j]);
    s.emplace(d);
  }
  FOR(j, 1, c) {
    int d = 0;
    FOR(i, 1, r) d = __gcd(d, ans[i][j]);
    s.emplace(d);
  }
  if (s.size() < r + c) {
    puts("0");
  } else {
    if (f) {
      FOR(j, 1, c) {
        FOR(i, 1, r) printf("%d ", ans[i][j]);
        putchar('\n');
      }
    } else {
      FOR(i, 1, r) {
        FOR(j, 1, c) printf("%d ", ans[i][j]);
        putchar('\n');
      }
    }
  }
}