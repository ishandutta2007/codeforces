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

int a[maxn], n;
int cnt[maxn][18], vis[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 2, 200000) if (!vis[i]) {
    vis[i] = i;
    for (int j = i + i; j <= 200000; j += i) if (!vis[j]) vis[j] = i;
  }
  FOR(i, 1, n) {
    map<int, int> have;
    while (a[i] != 1) {
      have[vis[a[i]]]++;
      a[i] /= vis[a[i]];
    }
    for (auto [p, c] : have) FOR(j, 1, c) cnt[p][j]++;
  }
  ll ans = 1;
  FOR(i, 1, 200000) if (vis[i] == i) FOR(j, 1, 17) {
    if (cnt[i][j] < n - 1) break;
    ans = ans * i;
  }
  printf("%lld", ans);
}