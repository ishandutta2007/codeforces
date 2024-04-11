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

int n;
ll lis[maxn];
vector<ll> hi[60], ans;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", lis + i);
  FOR(i, 1, n) ROF(j, 59, 0) if (lis[i] & (1LL << j)) {
        hi[j].eb(lis[i]);
        break;
      }
  ll now = 0;
  FOR(i, 1, n) {
    int idx = -1;
    REP(j, 60) if (!hi[j].empty() && !(now & (1LL << j))) {
        idx = j;
        break;
      }
    if (idx == -1) {
      puts("No");
      return 0;
    }
    now ^= hi[idx].back();
    ans.eb(hi[idx].back());
    hi[idx].pop_back();
  }
  puts("Yes");
  for (auto it : ans) printf("%lld ", it);
}