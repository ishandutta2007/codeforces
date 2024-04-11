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

const int maxn = 212345;

int n, k;
char a[maxn], b[maxn];

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", a);
  REP(i, k) b[i] = a[i];
  FOR(i, k, n - 1) b[i] = a[i % k];
  int p = -1;
  REP(i, n) if (b[i] != a[i]) {
    if (b[i] < a[i]) p = i;
    break;
  }
  if (~p) {
    ROF(i, k - 1, 0) if (b[i] < '9') {
      b[i]++;
      FOR(j, i + 1, k - 1) b[j] = '0';
      break;
    }
    FOR(i, k, n - 1) b[i] = b[i % k];
  }
  printf("%d\n", n);
  puts(b);
}