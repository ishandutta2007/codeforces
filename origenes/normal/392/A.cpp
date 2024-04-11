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

int main() {
  ll n;
  scanf("%lld", &n);
  if (!n) {
    puts("1");
    return 0;
  }
  int ans = 0;
  for (ll i = n, j = 0; i >= 0; i--) {
    ll pj = j;
    while (sqr(i) + sqr(j) <= sqr(n)) j++;
    j--;
    if (pj < j) ans += j - pj;
    else ans++;
  }
  ans--;
  printf("%d", ans * 4);
}