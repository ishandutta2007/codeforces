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

int a[maxn], n;
ll k;

int main() {
  scanf("%d%lld", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  map<ll, int> cnt;
  FOR(i, 1, n) cnt[a[i]]++;
  ll mn = cnt.begin()->_1, mx = cnt.rbegin()->_1;
  while (mn != mx && k > 0) {
    if (cnt[mn] < cnt[mx]) {
      int now = cnt[mn];
      cnt.erase(mn);
      ll nxt = cnt.begin()->_1;
      if ((nxt - mn) * now > k) {
        mn += k / now;
        cnt[mn] += now;
        k = 0;
      } else {
        cnt[nxt] += now;
        k -= (nxt - mn) * now;
      }
    } else {
      int now = cnt[mx];
      cnt.erase(mx);
      ll nxt = cnt.rbegin()->_1;
      if ((mx - nxt) * now > k) {
        mx -= k / now;
        cnt[mx] += now;
        k = 0;
      } else {
        cnt[nxt] += now;
        k -= (mx - nxt) * now;
      }
    }
    mn = cnt.begin()->_1, mx = cnt.rbegin()->_1;
  }
  mn = cnt.begin()->_1, mx = cnt.rbegin()->_1;
  printf("%lld", mx - mn);
}