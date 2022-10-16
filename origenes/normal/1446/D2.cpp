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
const int T = 450;

int n;
int a[maxn], pre[maxn], cnt[maxn], have[maxn];
vector<int> mark[maxn * 2];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cnt[a[i]]++;
  int target = 0, mx = 0;
  FOR(i, 1, n) if (cnt[i] > mx) {
    mx = cnt[i];
    target = i;
  }
  int ans = 0;
  FOR(i, 1, n) if (i != target && cnt[i] >= T) {
    mark[maxn].eb(0);
    FOR(j, 1, n) {
      pre[j] = pre[j - 1];
      if (a[j] == target) pre[j]--;
      else if (a[j] == i) pre[j]++;
      mark[pre[j] + maxn].eb(j);
    }
    FOR(j, 1, n) pre[j] = 0;
    FOR(j, -n, n) {
      if (mark[j + maxn].size() > 1) chkmax(ans, mark[j + maxn].back() - mark[j + maxn].front());
      mark[j + maxn].clear();
    }
  }
  FOR(i, 1, T - 1) {
    reset(have, 0);
    int peak = 0;
    int l = 1;
    FOR(r, 1, n) {
      int v = a[r];
      if (++have[v] == i) peak++;
      while (have[v] > i) {
        if (have[a[l]]-- == i) peak--;
        l++;
      }
      if (peak >= 2) chkmax(ans, r - l + 1);
    }
  }
  cout << ans;
}
/*
 10
1 4 2 5 2 6 1 1 2 1

 5
 1 1 1 1 1

 8
 2 3 2 3 4 4 4 4

 9
 2 3 2 2 1 2 3 3 3
 */