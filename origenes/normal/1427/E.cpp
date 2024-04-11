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

vector<tuple<char, ll, ll>> ans;
ll x;

int main() {
  scanf("%lld", &x);
  while (x > 1) {
    int k = 63 - __builtin_clzll(x);
    REP(i, k) ans.eb('+', x << i, x << i);
    ll a = x << k;
    ans.eb('^', a, x);
    ll b = a ^x;
    REP(i, k + 1) if (b & (1LL << i)) {
      ans.eb('+', a, x << i);
      a += x << i;
      ans.eb('+', b, x << i);
      b += x << i;
    }
    ans.eb('^', a, b);
    x = a ^ b;
  }
  printf("%d\n", int(ans.size()));
  for (auto [op, a, b] : ans) printf("%lld %c %lld\n", a, op, b);
}