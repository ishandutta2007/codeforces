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

const int maxn = 212345;

int n;
int a[4][maxn], cnt[4];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(j, 4) REP(i, n) cin >> a[j][i];
  ll ans = 0;
  REP(i, n) {
    REP(j, 4) {
      ans += cnt[j];
      if (a[j][i]) cnt[j]++;
    }
    REP(j, 2) if (cnt[j] && cnt[j + 2]) {
      int mn = min(cnt[j], cnt[j + 2]);
      cnt[j] -= mn, cnt[j + 2] -= mn;
    }
    REP(j, 2) if (cnt[j] && cnt[3 - j]) {
      int mn = min(cnt[j], cnt[3 - j]);
      ans += mn;
      cnt[j] -= mn, cnt[3 - j] -= mn;
    }
  }
  REP(j, 4) if (cnt[j]) {
    cout << -1;
    return 0;
  }
  cout << ans;
}