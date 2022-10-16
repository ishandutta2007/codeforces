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
vector<int> primes;

int T, n;

int main() {
  FOR(i, 2, 1e6) if (!vis[i]) {
    primes.eb(i);
    for (int j = i; j <= 1e6; j += i) vis[j] = true;
  }
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int x = lower_bound(all(primes), n + 1) - lower_bound(all(primes), sqrt(n + 0.5));
    printf("%d\n", x + 1);
  }
}