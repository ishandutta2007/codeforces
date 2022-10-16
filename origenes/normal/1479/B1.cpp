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
int a[maxn];
queue<int> q[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) q[a[i]].emplace(i);
  REP(i, n + 1) q[a[i]].emplace(n + 1);
  vector<int> v[2];
  FOR(i, 1, n) {
    int t0 = v[0].empty() ? 0 : v[0].back();
    int t1 = v[1].empty() ? 0 : v[1].back();
    if (t0 == t1) v[0].eb(a[i]);
    else if (t0 == a[i]) v[1].eb(a[i]);
    else if (t1 == a[i]) v[0].eb(a[i]);
    else {
      int nex0 = q[t0].front(), nex1 = q[t1].front();
      if (nex0 <= nex1) v[0].eb(a[i]);
      else v[1].eb(a[i]);
    }
    q[a[i]].pop();
  }
  uni(v[0]); uni(v[1]);
  cout << v[0].size() + v[1].size();
}