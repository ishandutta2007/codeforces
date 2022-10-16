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

const int maxn = 212345;
int n, s[maxn];
bool good[18][1 << 18];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", s + i);
  sort(s + 1, s + n + 1);
  ROF(bit, 18, 1) {
    good[bit - 1][0] = true;
    vector<int> base;
    FOR(i, 1, n) {
      if (s[i] >= 1 << bit) break;
      if (good[bit - 1][s[i]]) continue;
      REP(j, 1 << bit) if (good[bit - 1][j]) good[bit - 1][j ^ s[i]] = true;
      base.eb(s[i]);
    }
    if (base.size() == bit) {
      printf("%d\n", bit);
      int now = 0;
      printf("0");
      FOR(i, 1, (1 << bit) - 1) {
        int cnt = 0, j = i;
        while (!(j & 1)) j >>= 1, cnt++;
        now ^= base[cnt];
        printf(" %d", now);
      }
      return 0;
    }
  }
  printf("0\n0");
}