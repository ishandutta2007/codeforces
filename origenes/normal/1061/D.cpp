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

const int maxn = 112345;
const int MOD = 1e9 + 7;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n, ans, x, y, diff;
pii evt[maxn];

int main() {
  scanf("%d%d%d", &n, &x, &y);
  FOR(i, 1, n) scanf("%d%d", &evt[i]._1, &evt[i]._2);
  diff = (x + y - 1) / y;
  sort(evt + 1, evt + n + 1);
  multiset<int> ready, buff;
  FOR(i, 1, n) {
    while (!buff.empty()) {
      auto u = *buff.begin();
      if (u >= evt[i]._1) break;
      int to = buff.count(u);
      while (to--) ready.emplace(u);
      buff.erase(u);
    }
    while (!ready.empty()) {
      auto u = *ready.begin();
      if (u + diff > evt[i]._1) break;
      ready.erase(u);
    }
    if (!ready.empty()) {
      auto u = *ready.rbegin();
      ans = add(ans, mul(evt[i]._2 - u, y));
      ready.erase(ready.find(u)); buff.emplace(evt[i]._2);
    } else {
      ans = add(ans, add(x, mul(evt[i]._2 - evt[i]._1, y)));
      buff.emplace(evt[i]._2);
    }
  }
  printf("%d", ans);
}