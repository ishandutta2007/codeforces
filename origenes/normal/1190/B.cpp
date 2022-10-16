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

int n;
ll a[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", a + i);
  sort(a + 1, a + n + 1);
  ll have = 0;
  FOR(i, 1, n) have += a[i];
  have -= ll(n) * (n - 1) / 2;
  FOR(i, 1, n - 1) if (a[i] == a[i + 1]) {
    a[i]--;
    break;
  }
  if (a[1] == -1) puts("cslnb");
  else {
    FOR(i, 1, n - 1) if (a[i] == a[i + 1]) {
      puts("cslnb");
      return 0;
    }
    puts(have & 1 ? "sjfnb" : "cslnb");
  }
}