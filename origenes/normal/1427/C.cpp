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

const int maxn = 112345;

int f[maxn], mx[maxn], t[maxn], x[maxn], y[maxn];
int r, n;

int main() {
  scanf("%d%d", &r, &n);
  x[0] = y[0] = 1;
  FOR(i, 1, n) scanf("%d%d%d", t + i, x + i, y + i);
  FOR(i, 1, n) {
    f[i] = -1e9;
    int j = i - 1;
    while (j >= 0 && t[i] - t[j] <= 2 * (r - 1)) {
      if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) chkmax(f[i], f[j] + 1);
      j--;
    }
    if (j >= 0) chkmax(f[i], mx[j] + 1);
    mx[i] = max(f[i], mx[i - 1]);
  }
  printf("%d", mx[n]);
}