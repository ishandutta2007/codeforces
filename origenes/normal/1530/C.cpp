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

void solve() {
  int n; cin >> n;
  vector<int> ca(101), cb(101);
  REP(i, n) {
    int a; cin >> a;
    ca[a]++;
  }
  REP(i, n) {
    int b; cin >> b;
    cb[b]++;
  }
  int lo = 0, hi = 3 * n;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    ca[100] += mi;
    cb[0] += mi;
    int tot = n + mi, rem = tot / 4;
    int sa = 0, sb = 0, cur = 0;
    REP(i, 101) {
      if (ca[i] + cur <= rem) {
        cur += ca[i];
        continue;
      }
      if (cur >= rem) {
        sa += ca[i] * i;
        continue;
      }
      sa += (ca[i] - rem + cur) * i;
      cur = rem;
    }
    cur = 0;
    REP(i, 101) {
      if (cb[i] + cur <= rem) {
        cur += cb[i];
        continue;
      }
      if (cur >= rem) {
        sb += cb[i] * i;
        continue;
      }
      sb += (cb[i] - rem + cur) * i;
      cur = rem;
    }
    if (sa >= sb) hi = mi;
    else lo = mi + 1;
    ca[100] -= mi;
    cb[0] -= mi;
  }
  cout << lo << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}