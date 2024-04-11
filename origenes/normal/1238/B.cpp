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

int n, r;
int x[maxn];

void solve() {
  scanf("%d%d", &n, &r);
  FOR(i, 1, n) scanf("%d", x + i);
  set<int> alive;
  FOR(i, 1, n) alive.emplace(x[i]);
  int shift = 0, ans = 0;
  while (!alive.empty()) {
    auto c = *alive.rbegin();
    ans++;
    alive.erase(c);
    shift += r;
    while (!alive.empty() && *alive.begin() <= shift) alive.erase(alive.begin());
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}