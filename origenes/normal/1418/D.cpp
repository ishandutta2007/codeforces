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

int p[maxn];
int n, q;

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) scanf("%d", p + i);
  sort(p + 1, p + n + 1);
  set<int> s;
  map<int, int> Q;
  FOR(i, 1, n) s.emplace(p[i]);
  ll ans = 0;
  FOR(i, 1, n - 1) {
    Q[p[i + 1] - p[i]]++;
    ans += p[i + 1] - p[i];
  }
  printf("%lld\n", ans - (Q.empty() ? 0 : Q.rbegin()->_1));
  while (q--) {
    int t, x;
    scanf("%d%d", &t, &x);
    if (t == 0) {
      auto it1 = s.lower_bound(x), it2 = it1;
      it2++;
      int good = 0;
      if (it1 != s.begin()) {
        it1--;
        ans -= x - *it1;
        if (!--Q[x - *it1]) Q.erase(x - *it1);
        good++;
      }
      if (it2 != s.end()) {
        if (!--Q[*it2 - x]) Q.erase(*it2 - x);
        ans -= *it2 - x;
        good++;
      }
      if (good == 2) {
        Q[*it2 - *it1]++;
        ans += *it2 - *it1;
      }
      s.erase(x);
    } else {
      if (s.empty()) s.emplace(x);
      else {
        auto it2 = s.lower_bound(x);
        if (it2 == s.begin()) {
          Q[*it2 - x]++;
          ans += *it2 - x;
          s.emplace(x);
        } else if (it2 == s.end()) {
          it2--;
          Q[x - *it2]++;
          ans += x - *it2;
          s.emplace(x);
        } else {
          auto it1 = it2; it1--;
          if (!--Q[*it2 - *it1]) Q.erase(*it2 - *it1);
          Q[x - *it1]++, Q[*it2 - x]++;
          s.emplace(x);
        }
      }
    }
    printf("%lld\n", ans - (Q.empty() ? 0 : Q.rbegin()->_1));
  }
}