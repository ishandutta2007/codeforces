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

const int maxn = 112345;

ll n, k, p[maxn];
int m;

ll expand(ll st, int &j, ll now) {
  int cnt = 0;
  while (j <= m && p[j] - st < now) j++, cnt++;
  return cnt;
}

ll seek(ll pos, ll st) {
  return (pos - st) / k * k + st;
}

int main() {
  scanf("%lld%d%lld", &n, &m, &k);
  FOR(i, 1, m) {
    scanf("%lld", p + i);
    p[i]--;
  }
  int ans = 0, j = 1;
  ll st = 0;
  while (j <= m) {
    st = seek(p[j], st);
    ll now = k;
    int tmp;
    while (j <= m && (tmp = expand(st, j, now))) ans++, now += tmp;
    st += now;
  }
  printf("%d", ans);
}