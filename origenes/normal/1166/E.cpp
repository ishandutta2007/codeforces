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

const int maxm = 55;

bitset<10001> s[maxm];
int n, m;

int main() {
  scanf("%d%d", &m, &n);
  FOR(i, 1, m) {
    int tot;
    scanf("%d", &tot);
    while (tot--) {
      int now;
      scanf("%d", &now);
      s[i].set(now - 1);
    }
  }
  FOR(i, 1, m) FOR(j, i + 1, m) if ((s[i] & s[j]).none()) {
    puts("impossible");
    return 0;
  }
  puts("possible");
}