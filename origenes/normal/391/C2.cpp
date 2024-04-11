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

vector<int> G[maxn];
int n, k, cnt[maxn], p[maxn], e[maxn];

ll solve(int tar) {
  vector<int> same, diff;
  REP(i, tar - 1) for (auto j : G[i]) same.eb(j);
  if (tar >= 1) diff = G[tar - 1];
  for (auto j : G[tar]) diff.eb(j);
  FOR(i, tar + 1, 2e5) for (auto j : G[i]) same.eb(j);
  int need = n - k + 1, have = tar - 2 >= 0 ? cnt[tar - 2] : 0;
  ll ans = 0;
  sort(all(same)); sort(all(diff));
  int i = 0, j = 0;
  while (j < need - have) ans += diff[j++], tar--;
  while (i < int(same.size()) && j < int(diff.size()) && tar) {
    if (same[i] <= diff[j]) ans += same[i++];
    else ans += diff[j++];
    tar--;
  }
  while (i < int(same.size()) && tar) ans += same[i++], tar--;
  while (j < int(diff.size()) && tar) ans += diff[j++], tar--;
  return ans;
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) {
    scanf("%d%d", p + i, e + i);
    cnt[p[i]]++;
    G[p[i]].eb(e[i]);
  }
  FOR(i, 1, 2e5) cnt[i] += cnt[i - 1];
  int need = n - k + 1;
  if (cnt[n] < need) {
    puts("-1");
    return 0;
  }
  int j = 0;
  while (cnt[j] < need) j++;
  ll ans = solve(j);
  if (j + 1 <= n) chkmin(ans, solve(j + 1));
  if (j + 2 <= n) chkmin(ans, solve(j + 2));
  printf("%lld", ans);
}