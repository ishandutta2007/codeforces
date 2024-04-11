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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 5123;

vector<int> G[maxn];
int n, q, cnt[maxn], lis[maxn * maxn], pre, ans;

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, q) {
    int l, r;
    scanf("%d%d", &l, &r);
    FOR(j, l, r) if (G[j].size() < 3) G[j].eb(i);
  }
  FOR(i, 1, n) {
    if (G[i].size() > 2) continue;
    if (G[i].empty()) {
      pre++;
      continue;
    }
    if (G[i].size() == 1) cnt[G[i][0]]++;
    else lis[(G[i][0] - 1) * q + G[i][1] - 1]++;
  }
  FOR(i, 1, q) FOR(j, i + 1, q) {
      int idx = (i - 1) * q + j - 1;
      ans = chkmax(ans, n - cnt[i] - cnt[j] - lis[idx] - pre);
    }
  printf("%d", ans);
}