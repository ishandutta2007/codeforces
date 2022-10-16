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

int a[maxn], b[maxn], pos[maxn];
int n, ans;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) {
    scanf("%d", b + i);
    pos[b[i]] = i;
  }
  if (pos[1]) {
    int j = 2;
    while (pos[j] == pos[1] + j - 1) j++;
    if (pos[j - 1] == n) {
      int i = j;
      while (i <= n && pos[i] <= i - j) i++;
      if (i > n) {
        printf("%d", n - j + 1);
        return 0;
      }
    }
  }
  FOR(i, 1, n) chkmax(ans, pos[i] - i + 1 + n);
  printf("%d", ans);
}