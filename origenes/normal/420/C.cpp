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

int n, p;
int cnt[maxn], acc[maxn];
map<int, int> G[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> p;
  FOR(i, 1, n) {
    int x, y;
    cin >> x >> y;
    G[x][y]++;
    G[y][x]++;
    cnt[x]++, cnt[y]++;
  }
  FOR(i, 1, n) acc[cnt[i]]++;
  ROF(i, n, 0) acc[i] += acc[i + 1];
  ll ans = 0;
  FOR(i, 1, n) {
    int need = max(p - cnt[i], 0);
    int now = acc[need] - (cnt[i] >= need);
    for (auto [j, c] : G[i]) if (cnt[j] >= need && cnt[i] + cnt[j] - c < p) now--;
    ans += now;
  }
  cout << ans / 2;
}