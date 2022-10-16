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

int n, u, cnt[maxn], occ[maxn], ans;

int main() {
  scanf("%d", &n);
  set<int> s;
  FOR(i, 1, n) {
    scanf("%d", &u);
    s.emplace(u);
    occ[cnt[u]]--;
    cnt[u]++;
    occ[cnt[u]]++;
    if (s.size() == 1) ans = i;
    else {
      if (occ[1] >= i - 1) ans = i;
      else {
        int now = cnt[*s.begin()];
        if (occ[now] * ll(now) == i - 1 || ((occ[now] + 1) * ll(now) == i - 1 && occ[now + 1] == 1))
          ans = i;
        now = cnt[*s.rbegin()];
        if (occ[now] * ll(now) == i - 1 || ((occ[now] + 1) * ll(now) == i - 1 && occ[now + 1] == 1))
          ans = i;
      }
    }
  }
  printf("%d", ans);
}