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

const int maxk = 112345;

int k, ans[maxk];
ll n, tail;

ll get(ll a, ll b) {
  return (a + a + b - 1) * b >> 1;
}

int main() {
  scanf("%lld%d", &n, &k);
  FOR(i, 1, k) {
    ll now = tail + 1, rem = k - i + 1;
    ll diff = max(n - get(now, rem), 0LL);
    if (i > 1) now += min(tail - 1, diff / rem);
    else now += diff / rem;
    n -= now, tail = now, ans[i] = now;
  }
  if (n) puts("NO");
  else {
    puts("YES");
    FOR(i, 1, k) printf("%d ", ans[i]);
  }
}