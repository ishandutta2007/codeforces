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

const int maxn = 1123456;

int n;
int vis[maxn];
ll h[maxn], fac[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  iota(vis + 1, vis + n + 1, 1);
  FOR(i, 2, n) if (vis[i] == i) {
    for (int j = i + i; j <= n; j += i) vis[j] = i;
    h[i] = rng();
  }
  map<ll, int> rev;
  FOR(i, 2, n) {
    fac[i] = fac[i - 1];
    int now = i;
    while (now != 1) {
      fac[i] ^= h[vis[now]];
      now /= vis[now];
    }
    rev[fac[i]] = i;
  }
  ll tot = 0;
  FOR(i, 2, n) tot ^= fac[i];
  if (tot == 0) {
    cout << n << '\n';
    FOR(i, 1, n) cout << i << ' ';
    return 0;
  }
  if (rev.count(tot)) {
    cout << n - 1 << '\n';
    int bad = rev[tot];
    FOR(i, 1, n) if (i != bad) cout << i << ' ';
    return 0;
  }
  FOR(i, 2, n) {
    ll tmp = fac[i] ^ tot;
    if (rev.count(tmp) && rev[tmp] != i) {
      cout << n - 2 << '\n';
      int bad = rev[tmp];
      FOR(j, 1, n) if (j != bad && j != i) cout << j << ' ';
      return 0;
    }
  }
  cout << n - 3 << '\n';
  FOR(i, 1, n - 1) if (i != 2 && i != n / 2) cout << i << ' ';
}