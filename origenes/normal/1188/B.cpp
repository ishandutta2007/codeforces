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

int n, p, k, a[maxn];

int main() {
  scanf("%d%d%d", &n, &p, &k);
  map<int, int> cnt;
  FOR(i, 1, n) {
    scanf("%d", a + i);
    int now = (ll(a[i]) * a[i] % p * a[i] % p * a[i] % p - ll(k) * a[i] % p) % p;
    if (now < 0) now += p;
    cnt[now]++;
  }
  ll ans = 0;
  for (auto it : cnt) ans += ll(it._2) * (it._2 - 1) / 2;
  printf("%lld", ans);
}