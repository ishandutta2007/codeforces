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

const int maxn = 212345;

int n;
ll s;
int l[maxn], r[maxn];

bool check(int m) {
  int need = n + 1 >> 1;
  vector<int> extra;
  FOR(i, 1, n) {
    if (l[i] >= m) need--;
    else if (r[i] >= m) extra.eb(m - l[i]);
  }
  if (need <= 0) return true;
  if (extra.size() < need) return false;
  nth_element(extra.begin(), extra.begin() + need - 1, extra.end());
  ll have = s;
  REP(i, need) have -= extra[i];
  return have >= 0;
}

void solve() {
  scanf("%d%lld", &n, &s);
  FOR(i, 1, n) {
    scanf("%d%d", l + i, r + i);
    s -= l[i];
  }
  int lo = 0, hi = 1e9;
  while (lo < hi) {
    int mi = lo + hi + 1 >> 1;
    if (check(mi)) lo = mi;
    else hi = mi - 1;
  }
  printf("%d\n", lo);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}