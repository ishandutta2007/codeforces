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

const int maxn = 312345;

ll a[maxn], b[maxn];
int n, m, ans;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%lld", a + i);
    a[i] += a[i - 1];
  }
  scanf("%d", &m);
  FOR(i, 1, m) {
    scanf("%lld", b + i);
    b[i] += b[i - 1];
  }
  if (a[n] != b[m]) {
    puts("-1");
    return 0;
  }
  set<ll> s;
  FOR(i, 1, m) s.emplace(b[i]);
  FOR(i, 1, n) if (s.count(a[i])) ans++;
  printf("%d", ans);
}