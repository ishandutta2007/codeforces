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
ll a[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", a + i);
  ll A = 0, B = 0;
  FOR(i, 1, n) {
    A += a[i];
    B ^= a[i];
  }
  ll x = (1LL << 58) - A;
  ll d = (B ^ x) * 2 - (1LL << 58);
  assert(d >= 0);
  ll y = d / 2;
  printf("3\n");
  printf("%lld %lld %lld\n", x, y, y);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}