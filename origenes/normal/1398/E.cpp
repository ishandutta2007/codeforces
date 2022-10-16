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

int n;

int main() {
  scanf("%d", &n);
  map<int, int> lighting;
  map<int, int, greater<>> fi, se;
  int tot = 0, li = 0;
  ll sum = 0, fs = 0;
  while (n--) {
    int tp, d;
    scanf("%d%d", &tp, &d);
    if (tp == 0) {
      if (d > 0) {
        tot++;
        sum += d;
        if (!fi.empty() && d > fi.rbegin()->_1) {
          int v = fi.rbegin()->_1;
          se[v]++;
          fs += d - v;
          if (!--fi[v]) fi.erase(v);
          fi[d]++;
        } else se[d]++;
      } else {
        d = -d;
        tot--;
        sum -= d;
        if (!fi.empty() && d >= fi.rbegin()->_1) {
          if (!--fi[d]) fi.erase(d);
          fs -= d;
          if (!se.empty()) {
            int v = se.begin()->_1;
            fs += v;
            fi[v]++;
            if (!--se[v]) se.erase(v);
          }
        } else if (!--se[d]) se.erase(d);
      }
    } else {
      if (d > 0) {
        tot++, li++;
        sum += d;
        se[d]++;
        lighting[d]++;
        int v = se.begin()->_1;
        fs += v;
        fi[v]++;
        if (!--se[v]) se.erase(v);
      } else {
        d = -d;
        tot--, li--;
        sum -= d;
        if (!--lighting[d]) lighting.erase(d);
        if (d >= fi.rbegin()->_1) {
          fs -= d;
          if (!--fi[d]) fi.erase(d);
        } else {
          if (!--se[d]) se.erase(d);
          int v = fi.rbegin()->_1;
          fs -= v;
          if (!--fi[v]) fi.erase(v);
          se[v]++;
        }
      }
    }
    ll ans = sum;
    if (li > 0) {
      ans += fs;
      if (lighting.begin()->_1 >= fi.rbegin()->_1) {
        ans -= lighting.begin()->_1;
        if (!se.empty()) ans += se.begin()->_1;
      }
    }
    printf("%lld\n", ans);
  }
}