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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  vector<int> now;
  map<int, int> bans;
  int ans = 0;
  REP(i, n) {
    int a; cin >> a;
    if (a == 1) {
      ans++;
      now.clear();
      bans.clear();
    } else {
      int d = a, idx = i;
      ROF(j, size(now) - 1, 0) {
        d = gcd(d, now[j]);
        if (now[j] == d) break;
        idx--;
        if (!--bans[idx + now[j] - 1]) bans.erase(idx + now[j] - 1);
        now[j] = d;
        bans[idx + now[j] - 1]++;
      }
      if (bans.count(i)) {
        ans++;
        now.clear();
        bans.clear();
      } else {
        now.eb(a);
        bans[i + a - 1]++;
      }
    }
    cout << ans << ' ';
  }
}