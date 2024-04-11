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

int f[1 << 24], n;
char s[5];

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%s", s);
    int mask = 0;
    REP(i, 3) mask |= 1 << s[i] - 'a';
    for (int i = mask; i; i = (i - 1) & mask) {
      if (__builtin_popcount(i) & 1) f[i]++;
      else f[i]--;
    }
  }
  REP(i, 24) REP(mask, 1 << 24) if (mask & (1 << i)) f[mask] += f[mask ^ (1 << i)];
  int ans = 0;
  REP(mask, 1 << 24) ans ^= sqr(f[mask]);
  printf("%d", ans);
}