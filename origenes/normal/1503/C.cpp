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

int n;
int a[maxn], c[maxn], id[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i] >> c[i];
  iota(id + 1, id + n + 1, 1);
  sort(id + 1, id + n + 1, [](int x, int y) { return a[x] < a[y]; });
  int reach = a[id[1]] + c[id[1]];
  ll ans = 0;
  FOR(i, 1, n) {
    if (a[id[i]] > reach) ans += a[id[i]] - reach;
    chkmax(reach, a[id[i]] + c[id[i]]);
  }
  FOR(i, 1, n) ans += c[i];
  cout << ans;
}