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

ll n, m;
int q;

int main() {
  scanf("%lld%lld%d", &n, &m, &q);
  ll d = __gcd(n, m), bn = n / d, bm = m / d;
  while (q--) {
    ll sx, sy, ex, ey;
    scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
    sy--, ey--;
    ll i1 = sx == 1 ? sy / bn : sy / bm;
    ll i2 = ex == 1 ? ey / bn : ey / bm;
    puts(i1 == i2 ? "YES" : "NO");
  }
}