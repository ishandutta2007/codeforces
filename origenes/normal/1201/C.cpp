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
int a[maxn];

bool check(int x) {
  int have = k;
  FOR(i, n / 2 + 1, n) {
    if (a[i] >= x) return true;
    int need = x - a[i];
    if (have < need) return false;
    have -= need;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  int lo = a[n / 2 + 1], hi = a[n / 2 + 1] + k;
  while (lo < hi) {
    int mi = (hi - lo + 1) / 2 + lo;
    if (check(mi)) lo = mi;
    else hi = mi - 1;
  }
  printf("%d", lo);
}