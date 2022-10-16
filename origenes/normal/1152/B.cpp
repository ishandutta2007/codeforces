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

int main() {
  int x, ans = 0;
  scanf("%d", &x);
  int st;
  ROF(i, 20, 0) if (x & (1 << i)) {
    st = i;
    break;
  }
  int need = (1 << st + 1) - 1;
  vector<int> rec;
  ROF(i, st, 0) {
    if (x & (1 << i)) continue;
    x ^= (1 << i + 1) - 1;
    ans++;
    rec.eb(i + 1);
    if (x == need) break;
    x++, ans++;
  }
  printf("%d\n", ans);
  for (auto it : rec) printf("%d ", it);
}