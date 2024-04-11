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

const int maxn = 612345;
const int OFF = 2e5 + 5;

int n;
int b[maxn];
vector<int> G[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", b + i);
  FOR(i, 1, n) G[b[i] - i + OFF].eb(i);
  ll ans = *max_element(b + 1, b + n + 1);
  REP(i, maxn) if (G[i].size()) {
    ll now = 0;
    for (auto j : G[i]) now += b[j];
    chkmax(ans, now);
  }
  printf("%lld", ans);
}