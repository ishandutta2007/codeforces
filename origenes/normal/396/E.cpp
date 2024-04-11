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

int vis[maxn], primes[maxn], id[maxn], p[maxn];
ll a[maxn], buff[maxn], rem[maxn], k;
int pcnt, n;

int main() {
  FOR(i, 2, 1e6) {
    if (!vis[i]) {
      vis[i] = i;
      primes[++pcnt] = i;
      id[i] = pcnt;
    }
    FOR(j, 1, pcnt) {
      if (i * primes[j] > 1e6) break;
      vis[i * primes[j]] = primes[j];
      if (i % primes[j] == 0) break;
    }
  }
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", p + i);
    scanf("%lld", a + id[p[i]]);
  }
  scanf("%lld", &k);
  fill(rem + 1, rem + pcnt + 1, k);
  bool change;
  do {
    change = false;
    FOR(i, 1, pcnt) {
      if (a[i]) {
        if (!rem[i]) continue;
        ll cur = min(a[i], rem[i]);
        a[i] -= cur, rem[i] -= cur;
        buff[i] += cur - 1;
        change = true;
        int now = primes[i] - 1;
        while (now > 1) {
          a[id[vis[now]]] += cur;
          now /= vis[now];
        }
      } else if (buff[i]) buff[i]--;
      else if (rem[i]) rem[i]--;
    }
  } while (change);
  vector<pair<int, ll>> ans;
  FOR(i, 1, pcnt) if (a[i]) ans.eb(primes[i], a[i]);
  printf("%d\n", int(ans.size()));
  for (auto it : ans) printf("%d %lld\n", it._1, it._2);
}