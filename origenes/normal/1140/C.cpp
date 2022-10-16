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

const int maxn = 312345;

pii lis[maxn];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d%d", &lis[i]._2, &lis[i]._1);
  sort(lis + 1, lis + n + 1, greater<>());
  multiset<int> s;
  int tot = 0;
  ll ans = 0, now = 0;
  FOR(i, 1, n) {
    s.emplace(lis[i]._2);
    now += lis[i]._2;
    tot++;
    if (tot > k) {
      int del = *s.begin();
      now -= del;
      s.erase(s.find(del));
      tot = k;
    }
    chkmax(ans, lis[i]._1 * now);
  }
  printf("%lld", ans);
}