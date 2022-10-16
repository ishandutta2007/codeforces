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

int n, a[maxn];
int cnt[int(6e7) + maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n) cin >> a[i];
  int ans = 0;
  FOR(d, -300, 300) {
    vector<int> ver;
    REP(i, n) {
      int s = a[i] - i * d;
      cnt[s + int(3e7)]++;
      ver.eb(s + 3e7);
    }
    for (auto p : ver) {
      chkmax(ans, cnt[p]);
      cnt[p] = 0;
    }
  }
  REP(i, n) {
    vector<int> ver;
    for (int j = i + 1; j < min(n, i + 350); j++) {
      int d = a[j] - a[i];
      if (d % (j - i) != 0) continue;
      cnt[d / (j - i) + int(3e7)]++;
      ver.eb(d / (j - i) + 3e7);
    }
    for (auto p : ver) {
      chkmax(ans, cnt[p] + 1);
      cnt[p] = 0;
    }
  }
  cout << n - ans;
}