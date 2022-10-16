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

bool vis[maxn];
int phi[maxn];
int n, k;
vector<int> primes;
ll ans;

int main() {
  scanf("%d%d", &n, &k);
  if (k == 1) {
    puts("3");
    return 0;
  }
  phi[1] = 1; vis[1] = true;
  FOR(i, 2, n) {
    if (!vis[i]) {
      primes.eb(i);
      phi[i] = i - 1;
    }
    for (auto j : primes) {
      if (ll(j) * i > n) break;
      vis[j * i] = true;
      if (i % j == 0) {
        phi[i * j] = phi[i] * j;
        break;
      }
      phi[i * j] = phi[i] * (j - 1);
    }
  }
  vector<ll> v(phi + 3, phi + n + 1);
  nth_element(v.begin(), v.begin() + k - 1, v.end());
  ans = accumulate(v.begin(), v.begin() + k, 2LL);
  printf("%lld", ans);
}