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
int a[maxn], b[maxn], other[maxn], mx[maxn];
bool flip[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i] >> b[i];
    if (max(a[i], b[i]) <= n) {
      cout << -1;
      return 0;
    }
    if (a[i] < b[i]) other[a[i]] = b[i];
    else other[b[i]] = a[i], flip[b[i]] = true;
  }
  ROF(i, n, 1) mx[i] = max(mx[i + 1], other[i]);
  int mn = 1e9, cnt[2] = {};
  vector<int> v[2] = {};
  int ans = 0;
  FOR(i, 1, n) {
    chkmin(mn, other[i]);
    if (v[0].empty() || other[i] < v[0].back()) {
      v[0].eb(other[i]);
      cnt[0] += flip[i];
    } else if (v[1].empty() || other[i] < v[1].back()) {
      v[1].eb(other[i]);
      cnt[1] += flip[i];
    } else {
      cout << -1;
      return 0;
    }
    if (mn > mx[i + 1]) {
      ans += min(cnt[0] + v[1].size() - cnt[1], cnt[1] + v[0].size() - cnt[0]);
      cnt[0] = cnt[1] = 0;
      v[0].clear(); v[1].clear();
    }
  }
  cout << ans;
}