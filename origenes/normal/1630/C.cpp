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

const int maxn = 312345;

int n, a[maxn], st[maxn], en[maxn];
vector<int> occ[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) {
    if (occ[a[i]].size() < 2) occ[a[i]].eb(i);
    else {
      occ[a[i]].pop_back();
      occ[a[i]].eb(i);
    }
  }
  vector<pii> intervals;
  FOR(i, 1, n) if (occ[i].size() == 2) intervals.eb(occ[i][0], occ[i][1]);
  if (intervals.empty()) {
    cout << 0;
    return 0;
  }
  sort(all(intervals), [](pii x, pii y) { return x._1 != y._1 ? x._1 < y._1 : x._2 > y._2; });
  int r = intervals[0]._2;
  st[intervals[0]._1]++; en[intervals[0]._2]++;
  FOR(i, 1, int(intervals.size()) - 1) {
    if (intervals[i]._2 <= r) continue;
    int j = i, ni = i;
    while (j < size(intervals) && intervals[j]._1 <= r) {
      if (intervals[j]._2 > intervals[ni]._2) ni = j;
      j++;
    }
    r = intervals[ni]._2;
    st[intervals[ni]._1]++, en[intervals[ni]._2]++;
    i = ni;
  }
  int ans = 0, dep = 0, cnt = 0, len = 0;
  FOR(i, 1, n) {
    dep += st[i];
    cnt += st[i];
    if (dep) len++;
    dep -= en[i];
    if (!dep) {
      ans += max(len - cnt - 1, 0);
      cnt = len = 0;
    }
  }
  cout << ans;
}