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

multiset<int> que[31];
ll s[31];
int q, mmin[31], n;
char op[3];

int main() {
  scanf("%d", &q);
  reset(mmin, -1);
  while (q--) {
    int x;
    scanf("%s%d", op, &x);
    int idx, cnt = 0;
    FOR(i, 1, 30) if (x < 1 << i) {
      idx = i;
      break;
    }
    if (op[0] == '+') {
      que[idx].emplace(x);
      s[idx] += x;
      mmin[idx] = *que[idx].begin();
      n++;
    } else {
      auto it = que[idx].find(x);
      que[idx].erase(it);
      if (que[idx].empty()) mmin[idx] = -1;
      else mmin[idx] = *que[idx].begin();
      s[idx] -= x;
      n--;
    }
    ll tot = 0;
    FOR(i, 1, 30) {
      if (mmin[i] > 2 * tot) cnt++;
      tot += s[i];
    }
    printf("%d\n", n - cnt);
  }
}