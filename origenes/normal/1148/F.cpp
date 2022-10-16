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

bool vis[maxn];
int n, val[maxn];
ll mask[maxn], ans;

int main() {
  scanf("%d", &n);
  ll tot = 0;
  FOR(i, 1, n) {
    scanf("%d%lld", val + i, mask + i);
    tot += val[i];
  }
  if (tot < 0) FOR(i, 1, n) val[i] = -val[i];
  ROF(bit, 61, 0) {
    ll even = 0, odd = 0;
    FOR(i, 1, n) if (mask[i] == 1LL << bit) {
      if (!vis[i]) even += val[i];
      else odd += val[i];
    }
    if (even > odd) {
      ans |= (1LL << bit);
      FOR(i, 1, n) if (mask[i] & (1LL << bit)) vis[i] ^= true;
    }
    FOR(i, 1, n) mask[i] &= ~(1LL << bit);
  }
  printf("%lld", ans);
}