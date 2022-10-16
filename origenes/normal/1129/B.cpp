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

int k, pre = -1;

int main() {
  vector<int> ans(1, -1);
  scanf("%d", &k);
  while (pre - int(ans.size()) + 1 < k) {
    if (pre - int(ans.size()) + 1e6 >= k) {
      ans.eb(k + int(ans.size()) - pre);
      break;
    }
    pre += 1e6;
    ans.eb(1e6);
  }
  assert(ans.size() <= 2000);
  printf("%d\n", int(ans.size()));
  for (auto it : ans) printf("%d ", it);
}