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

int n, x, y;
int f[2][1 << 22], v[44];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> x >> y;
  if (x < y) swap(x, y);
  int p = x + y, ALL = (1 << x) - 1;
  REP(i, p) {
    v[i] = n / p;
    if (i < n % p) v[i]++;
  }
  REP(mask, 1 << x) f[0][mask] = -1e9;
  f[0][0] = 0;
  REP(i, p) {
    int now = i & 1, nxt = 1 - now;
    REP(mask, 1 << x) f[nxt][mask] = -1e9;
    REP(mask, 1 << x) if (f[now][mask] > -1e9) {
      int nmask = (mask << 1) & ALL;
      chkmax(f[nxt][nmask], f[now][mask]);
      if (mask & (1 << x - 1) || mask & (1 << y - 1)) continue;
      chkmax(f[nxt][nmask | 1], f[now][mask] + v[i]);
    }
  }
  cout << *max_element(f[p & 1], f[p & 1] + (1 << x));
}