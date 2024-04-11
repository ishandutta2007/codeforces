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

const int tab[] = {0, 2, 3, 1};

void solve() {
  ll n; scanf("%lld", &n);
  if (n <= 3) {
    printf("%lld\n", n);
    return;
  }
  ll r = (n + 2) / 3, c = (n - 1) % 3, base = 1;
  vector<ll> ans(3);
  while (true) {
    if (r <= base) {
      ans[0] = r + base - 1;
      break;
    }
    r -= base;
    base <<= 2;
  }
  r--;
  vector<int> num;
  while (r) {
    num.eb(r & 3);
    r >>= 2;
  }
  for (auto &x : num) x = tab[x];
  reverse(all(num));
  for (auto x : num) ans[1] = ans[1] * 4 + x;
  ans[1] += base * 2;
  ans[2] = ans[0] ^ ans[1];
  printf("%lld\n", ans[c]);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}